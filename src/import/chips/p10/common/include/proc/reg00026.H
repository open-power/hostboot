/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00026.H $         */
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

#ifndef __PROC_REG00026_H_
#define __PROC_REG00026_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[MCD_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_FIR_MASK_REG_RW]

//>> GET_[MCD_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, MCD_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_RW]

//>> PUT_[MCD_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MCD_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_FIR_MASK_REG_RW]

//>> PREP_[MCD_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_FIR_MASK_REG_WO_AND]

//>> GET_[MCD_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, MCD_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_WO_AND]

//>> PUT_[MCD_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MCD_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_FIR_MASK_REG_WO_AND]

//>> PREP_[MCD_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MCD_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MCD_FIR_MASK_REG_WO_OR]

//>> GET_[MCD_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MCD_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MCD_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, MCD_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_WO_OR]

//>> PUT_[MCD_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MCD_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MCD_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MCD_FIR_MASK_REG_WO_OR]


//>> SET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]

//>> SET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]

//>> SET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]

//>> GET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]

//>> GET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]
static inline bool GET_MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_ARRAY_ECC_UE_MASK]

//>> SET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]

//>> SET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]

//>> SET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]

//>> GET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]

//>> GET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]
static inline bool GET_MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_ARRAY_ECC_CE_MASK]

//>> SET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]

//>> SET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]

//>> SET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]

//>> GET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]

//>> GET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]
static inline bool GET_MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_PB_ADDR_PARITY_MASK]

//>> SET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_SM_OR_CASE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]

//>> SET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_SM_OR_CASE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]

//>> SET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_SM_OR_CASE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_SM_OR_CASE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]

//>> GET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_SM_OR_CASE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]

//>> GET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]
static inline bool GET_MCD_FIR_MASK_REG_SM_OR_CASE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_SM_OR_CASE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_SM_OR_CASE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_SM_OR_CASE_MASK]

//>> SET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]

//>> SET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]

//>> SET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]

//>> GET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]

//>> GET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]
static inline bool GET_MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_CL_PROBE_PB_HANG_MASK]

//>> SET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CRESP_ADDR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]

//>> SET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CRESP_ADDR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]

//>> SET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_CRESP_ADDR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_CRESP_ADDR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]

//>> GET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_CRESP_ADDR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]

//>> GET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]
static inline bool GET_MCD_FIR_MASK_REG_CRESP_ADDR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_CRESP_ADDR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_CRESP_ADDR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_CRESP_ADDR_MASK]

//>> SET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]

//>> SET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]

//>> SET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]

//>> GET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]

//>> GET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]
static inline bool GET_MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_UNSOLICITED_CRESP_MASK]

//>> SET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_TTAG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]

//>> SET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_TTAG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]

//>> SET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_TTAG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_TTAG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]

//>> GET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_TTAG_PARITY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]

//>> GET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]
static inline bool GET_MCD_FIR_MASK_REG_TTAG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_TTAG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_TTAG_PARITY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_TTAG_PARITY_MASK]

//>> SET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]

//>> SET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]

//>> SET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]

//>> GET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]

//>> GET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]
static inline bool GET_MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_FIR_REG_UPDATE_ERR_MASK]

//>> SET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]

//>> SET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]

//>> SET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]

//>> GET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]

//>> GET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]
static inline bool GET_MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_ACK_DEAD_CRESP_MASK]

//>> SET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]

//>> SET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]

//>> SET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]

//>> CLEAR_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]

//>> GET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]
static inline fapi2::buffer<uint64_t>& GET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]

//>> GET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]
static inline bool GET_MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MCD_FIR_MASK_REG_RW, MCD_FIR_MASK_REG_WO_AND, MCD_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MCD_FIR_MASK_REG_CFG_REG_PARITY_MASK]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]

//>> PREP_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW]

//>> PUT_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW]

//>> PREP_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND]

//>> PUT_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND]

//>> PREP_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR]

//>> PUT_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR]


//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_0_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_1_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_2_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_3_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_4_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_5_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_6_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]

//>> CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]
static inline bool GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW, PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND,
                           PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_MASK_REG_7_FIR_ERR_MASK]

//>> PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT]

//>> PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT]


//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_TM_MASTER_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE0]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_NP_CMD_RATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_AGGREGATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_INDIRECT_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_G_GATHER_ENABLE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_GP_CMD_RATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_AGGREGATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_INDIRECT_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_R_GATHER_ENABLE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE2]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MIN_SP_CMD_RATE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_SPARE3]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
