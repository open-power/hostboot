/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mc/reg00011.H $           */
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

#ifndef __MC_REG00011_H_
#define __MC_REG00011_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
{
#endif


//>> PREP_[ATOMIC_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATOMIC_LOCK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATOMIC_LOCK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ATOMIC_LOCK_REG]

//>> GET_[ATOMIC_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATOMIC_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATOMIC_LOCK_REG;
#endif
    return fapi2::getScom(i_target, ATOMIC_LOCK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ATOMIC_LOCK_REG]

//>> PUT_[ATOMIC_LOCK_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATOMIC_LOCK_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return fapi2::putScom(i_target, ATOMIC_LOCK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ATOMIC_LOCK_REG]


//>> SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_LOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_LOCK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_LOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.setBit<ATOMIC_LOCK_REG_LOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> CLEAR_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.clearBit<ATOMIC_LOCK_REG_LOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> GET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return i_data.extractToRight<ATOMIC_LOCK_REG_LOCK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> GET_[ATOMIC_LOCK_REG_LOCK_ENABLE]
static inline bool GET_ATOMIC_LOCK_REG_LOCK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return i_data.getBit<ATOMIC_LOCK_REG_LOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access ATOMIC_LOCK_REG_LOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATOMIC_LOCK_REG_LOCK_ENABLE]

//>> SET_[ATOMIC_LOCK_REG_ID]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_ID,
           ATOMIC_LOCK_REG_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_ID]

//>> SET_[ATOMIC_LOCK_REG_ID]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_ID,
           ATOMIC_LOCK_REG_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_ID]

//>> GET_[ATOMIC_LOCK_REG_ID]
static inline fapi2::buffer<uint64_t>& GET_ATOMIC_LOCK_REG_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return i_data.extractToRight<ATOMIC_LOCK_REG_ID,
           ATOMIC_LOCK_REG_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access ATOMIC_LOCK_REG_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATOMIC_LOCK_REG_ID]

//>> SET_[ATOMIC_LOCK_REG_ACTIVITY]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_ACTIVITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_ACTIVITY,
           ATOMIC_LOCK_REG_ACTIVITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_ACTIVITY]

//>> SET_[ATOMIC_LOCK_REG_ACTIVITY]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_REG_ACTIVITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_REG_ACTIVITY,
           ATOMIC_LOCK_REG_ACTIVITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_REG_ACTIVITY]

//>> GET_[ATOMIC_LOCK_REG_ACTIVITY]
static inline fapi2::buffer<uint64_t>& GET_ATOMIC_LOCK_REG_ACTIVITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_REG));
#endif
    return i_data.extractToRight<ATOMIC_LOCK_REG_ACTIVITY,
           ATOMIC_LOCK_REG_ACTIVITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access ATOMIC_LOCK_REG_ACTIVITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATOMIC_LOCK_REG_ACTIVITY]

//>> PREP_[ATTN_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATTN_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ATTN_INTERRUPT_REG]

//>> GET_[ATTN_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATTN_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, ATTN_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ATTN_INTERRUPT_REG]

//>> PUT_[ATTN_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, ATTN_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ATTN_INTERRUPT_REG]


//>> SET_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& SET_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<ATTN_INTERRUPT_REG_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATTN_INTERRUPT_REG_ATTN]

//>> SET_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& SET_ATTN_INTERRUPT_REG_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<ATTN_INTERRUPT_REG_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATTN_INTERRUPT_REG_ATTN]

//>> SET_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& SET_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return o_data.setBit<ATTN_INTERRUPT_REG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATTN_INTERRUPT_REG_ATTN]

//>> CLEAR_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return o_data.clearBit<ATTN_INTERRUPT_REG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ATTN_INTERRUPT_REG_ATTN]

//>> GET_[ATTN_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& GET_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return i_data.extractToRight<ATTN_INTERRUPT_REG_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATTN_INTERRUPT_REG_ATTN]

//>> GET_[ATTN_INTERRUPT_REG_ATTN]
static inline bool GET_ATTN_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATTN_INTERRUPT_REG));
#endif
    return i_data.getBit<ATTN_INTERRUPT_REG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access ATTN_INTERRUPT_REG_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATTN_INTERRUPT_REG_ATTN]

//>> PREP_[EPS_FIR_LOCAL_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_FIR_LOCAL_MASK_RW]

//>> GET_[EPS_FIR_LOCAL_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_MASK_RW;
#endif
    return fapi2::getScom(i_target, EPS_FIR_LOCAL_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_RW]

//>> PUT_[EPS_FIR_LOCAL_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, EPS_FIR_LOCAL_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_FIR_LOCAL_MASK_RW]

//>> PREP_[EPS_FIR_LOCAL_MASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_MASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_FIR_LOCAL_MASK_WO_AND]

//>> GET_[EPS_FIR_LOCAL_MASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_MASK_WO_AND;
#endif
    return fapi2::getScom(i_target, EPS_FIR_LOCAL_MASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_WO_AND]

//>> PUT_[EPS_FIR_LOCAL_MASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, EPS_FIR_LOCAL_MASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_FIR_LOCAL_MASK_WO_AND]

//>> PREP_[EPS_FIR_LOCAL_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_FIR_LOCAL_MASK_WO_OR]

//>> GET_[EPS_FIR_LOCAL_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, EPS_FIR_LOCAL_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_WO_OR]

//>> PUT_[EPS_FIR_LOCAL_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, EPS_FIR_LOCAL_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_FIR_LOCAL_MASK_WO_OR]


//>> SET_[EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_00]

//>> SET_[EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_00]

//>> SET_[EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_00]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_00]

//>> GET_[EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_00]

//>> GET_[EPS_FIR_LOCAL_MASK_00]
static inline bool GET_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_00]

//>> SET_[EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_01]

//>> SET_[EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_01]

//>> SET_[EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_01]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_01]

//>> GET_[EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_01]

//>> GET_[EPS_FIR_LOCAL_MASK_01]
static inline bool GET_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_01]

//>> SET_[EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_02]

//>> SET_[EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_02]

//>> SET_[EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_02]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_02]

//>> GET_[EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_02]

//>> GET_[EPS_FIR_LOCAL_MASK_02]
static inline bool GET_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_02]

//>> SET_[EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_03]

//>> SET_[EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_03]

//>> SET_[EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_03]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_03]

//>> GET_[EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_03]

//>> GET_[EPS_FIR_LOCAL_MASK_03]
static inline bool GET_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_03]

//>> SET_[EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_04]

//>> SET_[EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_04]

//>> SET_[EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_04]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_04]

//>> GET_[EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_04]

//>> GET_[EPS_FIR_LOCAL_MASK_04]
static inline bool GET_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_04]

//>> SET_[EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_05]

//>> SET_[EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_05]

//>> SET_[EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_05]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_05]

//>> GET_[EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_05]

//>> GET_[EPS_FIR_LOCAL_MASK_05]
static inline bool GET_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_05]

//>> SET_[EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_06]

//>> SET_[EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_06]

//>> SET_[EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_06]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_06]

//>> GET_[EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_06]

//>> GET_[EPS_FIR_LOCAL_MASK_06]
static inline bool GET_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_06]

//>> SET_[EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_07]

//>> SET_[EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_07]

//>> SET_[EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_07]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_07]

//>> GET_[EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_07]

//>> GET_[EPS_FIR_LOCAL_MASK_07]
static inline bool GET_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_07]

//>> SET_[EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_08]

//>> SET_[EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_08]

//>> SET_[EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_08]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_08]

//>> GET_[EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_08]

//>> GET_[EPS_FIR_LOCAL_MASK_08]
static inline bool GET_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_08]

//>> SET_[EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_09]

//>> SET_[EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_09]

//>> SET_[EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_09]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_09]

//>> GET_[EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_09]

//>> GET_[EPS_FIR_LOCAL_MASK_09]
static inline bool GET_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_09]

//>> SET_[EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_10]

//>> SET_[EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_10]

//>> SET_[EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_10]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_10]

//>> GET_[EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_10]

//>> GET_[EPS_FIR_LOCAL_MASK_10]
static inline bool GET_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_10]

//>> SET_[EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_11]

//>> SET_[EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_11]

//>> SET_[EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_11]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_11]

//>> GET_[EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_11]

//>> GET_[EPS_FIR_LOCAL_MASK_11]
static inline bool GET_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_11]

//>> SET_[EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_12]

//>> SET_[EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_12]

//>> SET_[EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_12]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_12]

//>> GET_[EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_12]

//>> GET_[EPS_FIR_LOCAL_MASK_12]
static inline bool GET_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_12]

//>> SET_[EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_13]

//>> SET_[EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_13]

//>> SET_[EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_13]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_13]

//>> GET_[EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_13]

//>> GET_[EPS_FIR_LOCAL_MASK_13]
static inline bool GET_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_13]

//>> SET_[EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_14]

//>> SET_[EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_14]

//>> SET_[EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_14]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_14]

//>> GET_[EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_14]

//>> GET_[EPS_FIR_LOCAL_MASK_14]
static inline bool GET_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_14]

//>> SET_[EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_15]

//>> SET_[EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_15]

//>> SET_[EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_15]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_15]

//>> GET_[EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_15]

//>> GET_[EPS_FIR_LOCAL_MASK_15]
static inline bool GET_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_15]

//>> SET_[EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_16]

//>> SET_[EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_16]

//>> SET_[EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_16]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_16]

//>> GET_[EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_16]

//>> GET_[EPS_FIR_LOCAL_MASK_16]
static inline bool GET_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_16]

//>> SET_[EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_17]

//>> SET_[EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_17]

//>> SET_[EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_17]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_17]

//>> GET_[EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_17]

//>> GET_[EPS_FIR_LOCAL_MASK_17]
static inline bool GET_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_17]

//>> SET_[EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_18]

//>> SET_[EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_18]

//>> SET_[EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_18]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_18]

//>> GET_[EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_18]

//>> GET_[EPS_FIR_LOCAL_MASK_18]
static inline bool GET_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_18]

//>> SET_[EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_19]

//>> SET_[EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_19]

//>> SET_[EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_19]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_19]

//>> GET_[EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_19]

//>> GET_[EPS_FIR_LOCAL_MASK_19]
static inline bool GET_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_19]

//>> SET_[EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_20]

//>> SET_[EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_20]

//>> SET_[EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_20]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_20]

//>> GET_[EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_20]

//>> GET_[EPS_FIR_LOCAL_MASK_20]
static inline bool GET_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_20]

//>> SET_[EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_21]

//>> SET_[EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_21]

//>> SET_[EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_21]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_21]

//>> GET_[EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_21]

//>> GET_[EPS_FIR_LOCAL_MASK_21]
static inline bool GET_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_21]

//>> SET_[EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_22]

//>> SET_[EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_22]

//>> SET_[EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_22]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_22]

//>> GET_[EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_22]

//>> GET_[EPS_FIR_LOCAL_MASK_22]
static inline bool GET_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_22]

//>> SET_[EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_23]

//>> SET_[EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_23]

//>> SET_[EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_23]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_23]

//>> GET_[EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_23]

//>> GET_[EPS_FIR_LOCAL_MASK_23]
static inline bool GET_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_23]

//>> SET_[EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_24]

//>> SET_[EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_24]

//>> SET_[EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_24]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_24]

//>> GET_[EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_24]

//>> GET_[EPS_FIR_LOCAL_MASK_24]
static inline bool GET_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_24]

//>> SET_[EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_25]

//>> SET_[EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_25]

//>> SET_[EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_25]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_25]

//>> GET_[EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_25]

//>> GET_[EPS_FIR_LOCAL_MASK_25]
static inline bool GET_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_25]

//>> SET_[EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_26]

//>> SET_[EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_26]

//>> SET_[EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_26]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_26]

//>> GET_[EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_26]

//>> GET_[EPS_FIR_LOCAL_MASK_26]
static inline bool GET_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_26]

//>> SET_[EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_27]

//>> SET_[EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_27]

//>> SET_[EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_27]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_27]

//>> GET_[EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_27]

//>> GET_[EPS_FIR_LOCAL_MASK_27]
static inline bool GET_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_27]

//>> SET_[EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_28]

//>> SET_[EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_28]

//>> SET_[EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_28]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_28]

//>> GET_[EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_28]

//>> GET_[EPS_FIR_LOCAL_MASK_28]
static inline bool GET_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_28]

//>> SET_[EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_29]

//>> SET_[EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_29]

//>> SET_[EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_29]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_29]

//>> GET_[EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_29]

//>> GET_[EPS_FIR_LOCAL_MASK_29]
static inline bool GET_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_29]

//>> SET_[EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_30]

//>> SET_[EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_30]

//>> SET_[EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_30]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_30]

//>> GET_[EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_30]

//>> GET_[EPS_FIR_LOCAL_MASK_30]
static inline bool GET_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_30]

//>> SET_[EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_31]

//>> SET_[EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_31]

//>> SET_[EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_31]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_31]

//>> GET_[EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_31]

//>> GET_[EPS_FIR_LOCAL_MASK_31]
static inline bool GET_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_31]

//>> SET_[EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_32]

//>> SET_[EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_32]

//>> SET_[EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_32]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_32]

//>> GET_[EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_32]

//>> GET_[EPS_FIR_LOCAL_MASK_32]
static inline bool GET_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_32]

//>> SET_[EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_33]

//>> SET_[EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_33]

//>> SET_[EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_33]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_33]

//>> GET_[EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_33]

//>> GET_[EPS_FIR_LOCAL_MASK_33]
static inline bool GET_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_33]

//>> SET_[EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_34]

//>> SET_[EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_34]

//>> SET_[EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_34]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_34]

//>> GET_[EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_34]

//>> GET_[EPS_FIR_LOCAL_MASK_34]
static inline bool GET_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_34]

//>> SET_[EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_35]

//>> SET_[EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_35]

//>> SET_[EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_35]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_35]

//>> GET_[EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_35]

//>> GET_[EPS_FIR_LOCAL_MASK_35]
static inline bool GET_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_35]

//>> SET_[EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_36]

//>> SET_[EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_36]

//>> SET_[EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_36]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_36]

//>> GET_[EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_36]

//>> GET_[EPS_FIR_LOCAL_MASK_36]
static inline bool GET_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_36]

//>> SET_[EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_37]

//>> SET_[EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_37]

//>> SET_[EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_37]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_37]

//>> GET_[EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_37]

//>> GET_[EPS_FIR_LOCAL_MASK_37]
static inline bool GET_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_37]

//>> SET_[EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_38]

//>> SET_[EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_38]

//>> SET_[EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_38]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_38]

//>> GET_[EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_38]

//>> GET_[EPS_FIR_LOCAL_MASK_38]
static inline bool GET_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_38]

//>> SET_[EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_39]

//>> SET_[EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_39]

//>> SET_[EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_39]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_39]

//>> GET_[EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_39]

//>> GET_[EPS_FIR_LOCAL_MASK_39]
static inline bool GET_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_39]

//>> SET_[EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_40]

//>> SET_[EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_40]

//>> SET_[EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_40]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_40]

//>> GET_[EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_40]

//>> GET_[EPS_FIR_LOCAL_MASK_40]
static inline bool GET_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_40]

//>> SET_[EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_41]

//>> SET_[EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_41]

//>> SET_[EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_41]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_41]

//>> GET_[EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_41]

//>> GET_[EPS_FIR_LOCAL_MASK_41]
static inline bool GET_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_41]

//>> SET_[EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_42]

//>> SET_[EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_42]

//>> SET_[EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_42]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_42]

//>> GET_[EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_42]

//>> GET_[EPS_FIR_LOCAL_MASK_42]
static inline bool GET_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_42]

//>> SET_[EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_43]

//>> SET_[EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_43]

//>> SET_[EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_43]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_43]

//>> GET_[EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_43]

//>> GET_[EPS_FIR_LOCAL_MASK_43]
static inline bool GET_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_43]

//>> SET_[EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_44]

//>> SET_[EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_44]

//>> SET_[EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_44]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_44]

//>> GET_[EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_44]

//>> GET_[EPS_FIR_LOCAL_MASK_44]
static inline bool GET_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_44]

//>> SET_[EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_45]

//>> SET_[EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_45]

//>> SET_[EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_45]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_45]

//>> GET_[EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_45]

//>> GET_[EPS_FIR_LOCAL_MASK_45]
static inline bool GET_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_45]

//>> SET_[EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_46]

//>> SET_[EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_46]

//>> SET_[EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_46]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_46]

//>> GET_[EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_46]

//>> GET_[EPS_FIR_LOCAL_MASK_46]
static inline bool GET_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_46]

//>> SET_[EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_47]

//>> SET_[EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_47]

//>> SET_[EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_47]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_47]

//>> GET_[EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_47]

//>> GET_[EPS_FIR_LOCAL_MASK_47]
static inline bool GET_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_47]

//>> SET_[EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_48]

//>> SET_[EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_48]

//>> SET_[EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_48]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_48]

//>> GET_[EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_48]

//>> GET_[EPS_FIR_LOCAL_MASK_48]
static inline bool GET_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_48]

//>> SET_[EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_49]

//>> SET_[EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_49]

//>> SET_[EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_49]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_49]

//>> GET_[EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_49]

//>> GET_[EPS_FIR_LOCAL_MASK_49]
static inline bool GET_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_49]

//>> SET_[EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_50]

//>> SET_[EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_50]

//>> SET_[EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_50]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_50]

//>> GET_[EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_50]

//>> GET_[EPS_FIR_LOCAL_MASK_50]
static inline bool GET_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_50]

//>> SET_[EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_51]

//>> SET_[EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_51]

//>> SET_[EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_51]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_51]

//>> GET_[EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_51]

//>> GET_[EPS_FIR_LOCAL_MASK_51]
static inline bool GET_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_51]

//>> SET_[EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_52]

//>> SET_[EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_52]

//>> SET_[EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_52]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_52]

//>> GET_[EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_52]

//>> GET_[EPS_FIR_LOCAL_MASK_52]
static inline bool GET_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_52]

//>> SET_[EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_53]

//>> SET_[EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_53]

//>> SET_[EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_53]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_53]

//>> GET_[EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_53]

//>> GET_[EPS_FIR_LOCAL_MASK_53]
static inline bool GET_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_53]

//>> SET_[EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_54]

//>> SET_[EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_54]

//>> SET_[EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_54]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_54]

//>> GET_[EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_54]

//>> GET_[EPS_FIR_LOCAL_MASK_54]
static inline bool GET_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_54]

//>> SET_[EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_55]

//>> SET_[EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_55]

//>> SET_[EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_55]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_55]

//>> GET_[EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_55]

//>> GET_[EPS_FIR_LOCAL_MASK_55]
static inline bool GET_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_55]

//>> SET_[EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_56]

//>> SET_[EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_56]

//>> SET_[EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_56]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_56]

//>> GET_[EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_56]

//>> GET_[EPS_FIR_LOCAL_MASK_56]
static inline bool GET_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_56]

//>> SET_[EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_57]

//>> SET_[EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_57]

//>> SET_[EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_57]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_57]

//>> GET_[EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_57]

//>> GET_[EPS_FIR_LOCAL_MASK_57]
static inline bool GET_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_57]

//>> SET_[EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_58]

//>> SET_[EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_58]

//>> SET_[EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_58]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_58]

//>> GET_[EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_58]

//>> GET_[EPS_FIR_LOCAL_MASK_58]
static inline bool GET_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_58]

//>> SET_[EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_59]

//>> SET_[EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_59]

//>> SET_[EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_59]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_59]

//>> GET_[EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_59]

//>> GET_[EPS_FIR_LOCAL_MASK_59]
static inline bool GET_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_59]

//>> SET_[EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_60]

//>> SET_[EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_60]

//>> SET_[EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_60]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_60]

//>> GET_[EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_60]

//>> GET_[EPS_FIR_LOCAL_MASK_60]
static inline bool GET_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_60]

//>> SET_[EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_61]

//>> SET_[EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_61]

//>> SET_[EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_61]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_61]

//>> GET_[EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_61]

//>> GET_[EPS_FIR_LOCAL_MASK_61]
static inline bool GET_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_61]

//>> SET_[EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_62]

//>> SET_[EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_62]

//>> SET_[EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_62]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_62]

//>> GET_[EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_62]

//>> GET_[EPS_FIR_LOCAL_MASK_62]
static inline bool GET_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_62]

//>> SET_[EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_63]

//>> SET_[EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_63]

//>> SET_[EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_MASK_63]

//>> CLEAR_[EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_MASK_63]

//>> GET_[EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_MASK_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_63]

//>> GET_[EPS_FIR_LOCAL_MASK_63]
static inline bool GET_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_MASK_RW, EPS_FIR_LOCAL_MASK_WO_AND, EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_MASK_63]

//>> PREP_[LOCAL_FIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_FIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_FIR_RW]

//>> GET_[LOCAL_FIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_FIR_RW;
#endif
    return fapi2::getScom(i_target, LOCAL_FIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_FIR_RW]

//>> PUT_[LOCAL_FIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, LOCAL_FIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_FIR_RW]

//>> PREP_[LOCAL_FIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_FIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_FIR_WO_AND]

//>> GET_[LOCAL_FIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_FIR_WO_AND;
#endif
    return fapi2::getScom(i_target, LOCAL_FIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_FIR_WO_AND]

//>> PUT_[LOCAL_FIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, LOCAL_FIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_FIR_WO_AND]

//>> PREP_[LOCAL_FIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_FIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_FIR_WO_OR]

//>> GET_[LOCAL_FIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_FIR_WO_OR;
#endif
    return fapi2::getScom(i_target, LOCAL_FIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_FIR_WO_OR]

//>> PUT_[LOCAL_FIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, LOCAL_FIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_FIR_WO_OR]


//>> SET_[LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_CFIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CFIR]

//>> SET_[LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CFIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_CFIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CFIR]

//>> SET_[LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CFIR]

//>> CLEAR_[LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_CFIR]

//>> GET_[LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_CFIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_CFIR]

//>> GET_[LOCAL_FIR_CFIR]
static inline bool GET_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_CFIR]

//>> SET_[LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_CPLT_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CPLT_CTRL]

//>> SET_[LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CPLT_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_CPLT_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CPLT_CTRL]

//>> SET_[LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CPLT_CTRL]

//>> CLEAR_[LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_CPLT_CTRL]

//>> GET_[LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_CPLT_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_CPLT_CTRL]

//>> GET_[LOCAL_FIR_CPLT_CTRL]
static inline bool GET_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_CPLT_CTRL]

//>> SET_[LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_CC_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CC_PCB]

//>> SET_[LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CC_PCB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_CC_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CC_PCB]

//>> SET_[LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CC_PCB]

//>> CLEAR_[LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_CC_PCB]

//>> GET_[LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_CC_PCB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_CC_PCB]

//>> GET_[LOCAL_FIR_CC_PCB]
static inline bool GET_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_CC_PCB]

//>> SET_[LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_CC_OTHERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CC_OTHERS]

//>> SET_[LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CC_OTHERS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_CC_OTHERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CC_OTHERS]

//>> SET_[LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_CC_OTHERS]

//>> CLEAR_[LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_CC_OTHERS]

//>> GET_[LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_CC_OTHERS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_CC_OTHERS]

//>> GET_[LOCAL_FIR_CC_OTHERS]
static inline bool GET_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_CC_OTHERS]

//>> SET_[LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN04]

//>> SET_[LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN04]

//>> SET_[LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN04]

//>> CLEAR_[LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN04]

//>> GET_[LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN04]

//>> GET_[LOCAL_FIR_IN04]
static inline bool GET_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN04]

//>> SET_[LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN05]

//>> SET_[LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN05]

//>> SET_[LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN05]

//>> CLEAR_[LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN05]

//>> GET_[LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN05]

//>> GET_[LOCAL_FIR_IN05]
static inline bool GET_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN05]

//>> SET_[LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN06]

//>> SET_[LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN06]

//>> SET_[LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN06]

//>> CLEAR_[LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN06]

//>> GET_[LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN06]

//>> GET_[LOCAL_FIR_IN06]
static inline bool GET_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN06]

//>> SET_[LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN07]

//>> SET_[LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN07]

//>> SET_[LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN07]

//>> CLEAR_[LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN07]

//>> GET_[LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN07]

//>> GET_[LOCAL_FIR_IN07]
static inline bool GET_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN07]

//>> SET_[LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN08]

//>> SET_[LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN08]

//>> SET_[LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN08]

//>> CLEAR_[LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN08]

//>> GET_[LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN08]

//>> GET_[LOCAL_FIR_IN08]
static inline bool GET_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN08]

//>> SET_[LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN09]

//>> SET_[LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN09]

//>> SET_[LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN09]

//>> CLEAR_[LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN09]

//>> GET_[LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN09]

//>> GET_[LOCAL_FIR_IN09]
static inline bool GET_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN09]

//>> SET_[LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN10]

//>> SET_[LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN10]

//>> SET_[LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN10]

//>> CLEAR_[LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN10]

//>> GET_[LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN10]

//>> GET_[LOCAL_FIR_IN10]
static inline bool GET_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN10]

//>> SET_[LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN11]

//>> SET_[LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN11]

//>> SET_[LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN11]

//>> CLEAR_[LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN11]

//>> GET_[LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN11]

//>> GET_[LOCAL_FIR_IN11]
static inline bool GET_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN11]

//>> SET_[LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN12]

//>> SET_[LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN12]

//>> SET_[LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN12]

//>> CLEAR_[LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN12]

//>> GET_[LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN12]

//>> GET_[LOCAL_FIR_IN12]
static inline bool GET_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN12]

//>> SET_[LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN13]

//>> SET_[LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN13]

//>> SET_[LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN13]

//>> CLEAR_[LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN13]

//>> GET_[LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN13]

//>> GET_[LOCAL_FIR_IN13]
static inline bool GET_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN13]

//>> SET_[LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN14]

//>> SET_[LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN14]

//>> SET_[LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN14]

//>> CLEAR_[LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN14]

//>> GET_[LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN14]

//>> GET_[LOCAL_FIR_IN14]
static inline bool GET_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN14]

//>> SET_[LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN15]

//>> SET_[LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN15]

//>> SET_[LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN15]

//>> CLEAR_[LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN15]

//>> GET_[LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN15]

//>> GET_[LOCAL_FIR_IN15]
static inline bool GET_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN15]

//>> SET_[LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN16]

//>> SET_[LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN16]

//>> SET_[LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN16]

//>> CLEAR_[LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN16]

//>> GET_[LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN16]

//>> GET_[LOCAL_FIR_IN16]
static inline bool GET_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN16]

//>> SET_[LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN17]

//>> SET_[LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN17]

//>> SET_[LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN17]

//>> CLEAR_[LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN17]

//>> GET_[LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN17]

//>> GET_[LOCAL_FIR_IN17]
static inline bool GET_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN17]

//>> SET_[LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN18]

//>> SET_[LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN18]

//>> SET_[LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN18]

//>> CLEAR_[LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN18]

//>> GET_[LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN18]

//>> GET_[LOCAL_FIR_IN18]
static inline bool GET_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN18]

//>> SET_[LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN19]

//>> SET_[LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN19]

//>> SET_[LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN19]

//>> CLEAR_[LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN19]

//>> GET_[LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN19]

//>> GET_[LOCAL_FIR_IN19]
static inline bool GET_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN19]

//>> SET_[LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN20]

//>> SET_[LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN20]

//>> SET_[LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN20]

//>> CLEAR_[LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN20]

//>> GET_[LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN20]

//>> GET_[LOCAL_FIR_IN20]
static inline bool GET_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN20]

//>> SET_[LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN21]

//>> SET_[LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN21]

//>> SET_[LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN21]

//>> CLEAR_[LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN21]

//>> GET_[LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN21]

//>> GET_[LOCAL_FIR_IN21]
static inline bool GET_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN21]

//>> SET_[LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN22]

//>> SET_[LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN22]

//>> SET_[LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN22]

//>> CLEAR_[LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN22]

//>> GET_[LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN22]

//>> GET_[LOCAL_FIR_IN22]
static inline bool GET_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN22]

//>> SET_[LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN23]

//>> SET_[LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN23]

//>> SET_[LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN23]

//>> CLEAR_[LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN23]

//>> GET_[LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN23]

//>> GET_[LOCAL_FIR_IN23]
static inline bool GET_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN23]

//>> SET_[LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN24]

//>> SET_[LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN24]

//>> SET_[LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN24]

//>> CLEAR_[LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN24]

//>> GET_[LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN24]

//>> GET_[LOCAL_FIR_IN24]
static inline bool GET_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN24]

//>> SET_[LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN25]

//>> SET_[LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN25]

//>> SET_[LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN25]

//>> CLEAR_[LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN25]

//>> GET_[LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN25]

//>> GET_[LOCAL_FIR_IN25]
static inline bool GET_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN25]

//>> SET_[LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN26]

//>> SET_[LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN26]

//>> SET_[LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN26]

//>> CLEAR_[LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN26]

//>> GET_[LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN26]

//>> GET_[LOCAL_FIR_IN26]
static inline bool GET_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN26]

//>> SET_[LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN27]

//>> SET_[LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN27]

//>> SET_[LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN27]

//>> CLEAR_[LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN27]

//>> GET_[LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN27]

//>> GET_[LOCAL_FIR_IN27]
static inline bool GET_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN27]

//>> SET_[LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN28]

//>> SET_[LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN28]

//>> SET_[LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN28]

//>> CLEAR_[LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN28]

//>> GET_[LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN28]

//>> GET_[LOCAL_FIR_IN28]
static inline bool GET_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN28]

//>> SET_[LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN29]

//>> SET_[LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN29]

//>> SET_[LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN29]

//>> CLEAR_[LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN29]

//>> GET_[LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN29]

//>> GET_[LOCAL_FIR_IN29]
static inline bool GET_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN29]

//>> SET_[LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN30]

//>> SET_[LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN30]

//>> SET_[LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN30]

//>> CLEAR_[LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN30]

//>> GET_[LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN30]

//>> GET_[LOCAL_FIR_IN30]
static inline bool GET_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN30]

//>> SET_[LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN31]

//>> SET_[LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN31]

//>> SET_[LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN31]

//>> CLEAR_[LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN31]

//>> GET_[LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN31]

//>> GET_[LOCAL_FIR_IN31]
static inline bool GET_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN31]

//>> SET_[LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN32]

//>> SET_[LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN32]

//>> SET_[LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN32]

//>> CLEAR_[LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN32]

//>> GET_[LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN32]

//>> GET_[LOCAL_FIR_IN32]
static inline bool GET_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN32]

//>> SET_[LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN33]

//>> SET_[LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN33]

//>> SET_[LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN33]

//>> CLEAR_[LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN33]

//>> GET_[LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN33]

//>> GET_[LOCAL_FIR_IN33]
static inline bool GET_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN33]

//>> SET_[LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN34]

//>> SET_[LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN34]

//>> SET_[LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN34]

//>> CLEAR_[LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN34]

//>> GET_[LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN34]

//>> GET_[LOCAL_FIR_IN34]
static inline bool GET_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN34]

//>> SET_[LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN35]

//>> SET_[LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN35]

//>> SET_[LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN35]

//>> CLEAR_[LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN35]

//>> GET_[LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN35]

//>> GET_[LOCAL_FIR_IN35]
static inline bool GET_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN35]

//>> SET_[LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN36]

//>> SET_[LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN36]

//>> SET_[LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN36]

//>> CLEAR_[LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN36]

//>> GET_[LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN36]

//>> GET_[LOCAL_FIR_IN36]
static inline bool GET_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN36]

//>> SET_[LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN37]

//>> SET_[LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN37]

//>> SET_[LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN37]

//>> CLEAR_[LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN37]

//>> GET_[LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN37]

//>> GET_[LOCAL_FIR_IN37]
static inline bool GET_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN37]

//>> SET_[LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN38]

//>> SET_[LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN38]

//>> SET_[LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN38]

//>> CLEAR_[LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN38]

//>> GET_[LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN38]

//>> GET_[LOCAL_FIR_IN38]
static inline bool GET_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN38]

//>> SET_[LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN39]

//>> SET_[LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN39]

//>> SET_[LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN39]

//>> CLEAR_[LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN39]

//>> GET_[LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN39]

//>> GET_[LOCAL_FIR_IN39]
static inline bool GET_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN39]

//>> SET_[LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN40]

//>> SET_[LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN40]

//>> SET_[LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN40]

//>> CLEAR_[LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN40]

//>> GET_[LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN40]

//>> GET_[LOCAL_FIR_IN40]
static inline bool GET_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN40]

//>> SET_[LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN41]

//>> SET_[LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN41]

//>> SET_[LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN41]

//>> CLEAR_[LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN41]

//>> GET_[LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN41]

//>> GET_[LOCAL_FIR_IN41]
static inline bool GET_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN41]

//>> SET_[LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN42]

//>> SET_[LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN42]

//>> SET_[LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN42]

//>> CLEAR_[LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN42]

//>> GET_[LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN42]

//>> GET_[LOCAL_FIR_IN42]
static inline bool GET_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN42]

//>> SET_[LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN43]

//>> SET_[LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN43]

//>> SET_[LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN43]

//>> CLEAR_[LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN43]

//>> GET_[LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN43]

//>> GET_[LOCAL_FIR_IN43]
static inline bool GET_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN43]

//>> SET_[LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN44]

//>> SET_[LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN44]

//>> SET_[LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN44]

//>> CLEAR_[LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN44]

//>> GET_[LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN44]

//>> GET_[LOCAL_FIR_IN44]
static inline bool GET_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN44]

//>> SET_[LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN45]

//>> SET_[LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN45]

//>> SET_[LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN45]

//>> CLEAR_[LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN45]

//>> GET_[LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN45]

//>> GET_[LOCAL_FIR_IN45]
static inline bool GET_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN45]

//>> SET_[LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN46]

//>> SET_[LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN46]

//>> SET_[LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN46]

//>> CLEAR_[LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN46]

//>> GET_[LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN46]

//>> GET_[LOCAL_FIR_IN46]
static inline bool GET_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN46]

//>> SET_[LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN47]

//>> SET_[LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN47]

//>> SET_[LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN47]

//>> CLEAR_[LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN47]

//>> GET_[LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN47]

//>> GET_[LOCAL_FIR_IN47]
static inline bool GET_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN47]

//>> SET_[LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN48]

//>> SET_[LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN48]

//>> SET_[LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN48]

//>> CLEAR_[LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN48]

//>> GET_[LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN48]

//>> GET_[LOCAL_FIR_IN48]
static inline bool GET_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN48]

//>> SET_[LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN49]

//>> SET_[LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN49]

//>> SET_[LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN49]

//>> CLEAR_[LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN49]

//>> GET_[LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN49]

//>> GET_[LOCAL_FIR_IN49]
static inline bool GET_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN49]

//>> SET_[LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN50]

//>> SET_[LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN50]

//>> SET_[LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN50]

//>> CLEAR_[LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN50]

//>> GET_[LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN50]

//>> GET_[LOCAL_FIR_IN50]
static inline bool GET_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN50]

//>> SET_[LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN51]

//>> SET_[LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN51]

//>> SET_[LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN51]

//>> CLEAR_[LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN51]

//>> GET_[LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN51]

//>> GET_[LOCAL_FIR_IN51]
static inline bool GET_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN51]

//>> SET_[LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN52]

//>> SET_[LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN52]

//>> SET_[LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN52]

//>> CLEAR_[LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN52]

//>> GET_[LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN52]

//>> GET_[LOCAL_FIR_IN52]
static inline bool GET_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN52]

//>> SET_[LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN53]

//>> SET_[LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN53]

//>> SET_[LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN53]

//>> CLEAR_[LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN53]

//>> GET_[LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN53]

//>> GET_[LOCAL_FIR_IN53]
static inline bool GET_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN53]

//>> SET_[LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN54]

//>> SET_[LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN54]

//>> SET_[LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN54]

//>> CLEAR_[LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN54]

//>> GET_[LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN54]

//>> GET_[LOCAL_FIR_IN54]
static inline bool GET_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN54]

//>> SET_[LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN55]

//>> SET_[LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN55]

//>> SET_[LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN55]

//>> CLEAR_[LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN55]

//>> GET_[LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN55]

//>> GET_[LOCAL_FIR_IN55]
static inline bool GET_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN55]

//>> SET_[LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN56]

//>> SET_[LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN56]

//>> SET_[LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN56]

//>> CLEAR_[LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN56]

//>> GET_[LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN56]

//>> GET_[LOCAL_FIR_IN56]
static inline bool GET_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN56]

//>> SET_[LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN57]

//>> SET_[LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN57]

//>> SET_[LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN57]

//>> CLEAR_[LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN57]

//>> GET_[LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN57]

//>> GET_[LOCAL_FIR_IN57]
static inline bool GET_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN57]

//>> SET_[LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN58]

//>> SET_[LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN58]

//>> SET_[LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN58]

//>> CLEAR_[LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN58]

//>> GET_[LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN58]

//>> GET_[LOCAL_FIR_IN58]
static inline bool GET_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN58]

//>> SET_[LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN59]

//>> SET_[LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN59]

//>> SET_[LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN59]

//>> CLEAR_[LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN59]

//>> GET_[LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN59]

//>> GET_[LOCAL_FIR_IN59]
static inline bool GET_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN59]

//>> SET_[LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN60]

//>> SET_[LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN60]

//>> SET_[LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN60]

//>> CLEAR_[LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN60]

//>> GET_[LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN60]

//>> GET_[LOCAL_FIR_IN60]
static inline bool GET_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN60]

//>> SET_[LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN61]

//>> SET_[LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN61]

//>> SET_[LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN61]

//>> CLEAR_[LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN61]

//>> GET_[LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN61]

//>> GET_[LOCAL_FIR_IN61]
static inline bool GET_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN61]

//>> SET_[LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN62]

//>> SET_[LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_IN62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN62]

//>> SET_[LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_IN62]

//>> CLEAR_[LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_IN62]

//>> GET_[LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_IN62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN62]

//>> GET_[LOCAL_FIR_IN62]
static inline bool GET_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_IN62]

//>> SET_[LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> SET_[LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_EXT_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> SET_[LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> CLEAR_[LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> GET_[LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> GET_[LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline bool GET_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_FIR_RW, LOCAL_FIR_WO_AND, LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> PREP_[RECOV]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RECOV(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RECOV]

//>> GET_[RECOV]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RECOV(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV;
#endif
    return fapi2::getScom(i_target, RECOV, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RECOV]

//>> PUT_[RECOV]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RECOV(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return fapi2::putScom(i_target, RECOV, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RECOV]


//>> SET_[RECOV_ANY_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_ANY_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_ANY_RECOV]

//>> SET_[RECOV_ANY_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_ANY_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_ANY_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_ANY_RECOV]

//>> SET_[RECOV_ANY_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_ANY_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_ANY_RECOV]

//>> CLEAR_[RECOV_ANY_RECOV]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_ANY_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_ANY_RECOV]

//>> GET_[RECOV_ANY_RECOV]
static inline fapi2::buffer<uint64_t>& GET_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_ANY_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_ANY_RECOV]

//>> GET_[RECOV_ANY_RECOV]
static inline bool GET_RECOV_ANY_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_ANY_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_ANY_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_ANY_RECOV]

//>> SET_[RECOV_RESERVED1R]
static inline fapi2::buffer<uint64_t>& SET_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_RESERVED1R,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_RESERVED1R]

//>> SET_[RECOV_RESERVED1R]
static inline fapi2::buffer<uint64_t>& SET_RECOV_RESERVED1R(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_RESERVED1R,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_RESERVED1R]

//>> SET_[RECOV_RESERVED1R]
static inline fapi2::buffer<uint64_t>& SET_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_RESERVED1R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_RESERVED1R]

//>> CLEAR_[RECOV_RESERVED1R]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_RESERVED1R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_RESERVED1R]

//>> GET_[RECOV_RESERVED1R]
static inline fapi2::buffer<uint64_t>& GET_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_RESERVED1R,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_RESERVED1R]

//>> GET_[RECOV_RESERVED1R]
static inline bool GET_RECOV_RESERVED1R(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_RESERVED1R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_RESERVED1R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_RESERVED1R]

//>> SET_[RECOV_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_ANY_LOCAL_XSTOP]

//>> SET_[RECOV_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_RECOV_ANY_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_ANY_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_ANY_LOCAL_XSTOP]

//>> SET_[RECOV_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_ANY_LOCAL_XSTOP]

//>> CLEAR_[RECOV_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_ANY_LOCAL_XSTOP]

//>> GET_[RECOV_ANY_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_ANY_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_ANY_LOCAL_XSTOP]

//>> GET_[RECOV_ANY_LOCAL_XSTOP]
static inline bool GET_RECOV_ANY_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_ANY_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_ANY_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_ANY_LOCAL_XSTOP]

//>> SET_[RECOV_RESERVED3R]
static inline fapi2::buffer<uint64_t>& SET_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_RESERVED3R,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_RESERVED3R]

//>> SET_[RECOV_RESERVED3R]
static inline fapi2::buffer<uint64_t>& SET_RECOV_RESERVED3R(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_RESERVED3R,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_RESERVED3R]

//>> SET_[RECOV_RESERVED3R]
static inline fapi2::buffer<uint64_t>& SET_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_RESERVED3R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_RESERVED3R]

//>> CLEAR_[RECOV_RESERVED3R]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_RESERVED3R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_RESERVED3R]

//>> GET_[RECOV_RESERVED3R]
static inline fapi2::buffer<uint64_t>& GET_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_RESERVED3R,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_RESERVED3R]

//>> GET_[RECOV_RESERVED3R]
static inline bool GET_RECOV_RESERVED3R(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_RESERVED3R>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_RESERVED3R chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_RESERVED3R]

//>> SET_[RECOV_PERV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_PERV]

//>> SET_[RECOV_PERV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_PERV]

//>> SET_[RECOV_PERV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_PERV]

//>> CLEAR_[RECOV_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_PERV]

//>> GET_[RECOV_PERV]
static inline fapi2::buffer<uint64_t>& GET_RECOV_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_PERV]

//>> GET_[RECOV_PERV]
static inline bool GET_RECOV_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_PERV]

//>> SET_[RECOV_IN05]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN05]

//>> SET_[RECOV_IN05]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN05]

//>> SET_[RECOV_IN05]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN05]

//>> CLEAR_[RECOV_IN05]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN05]

//>> GET_[RECOV_IN05]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN05]

//>> GET_[RECOV_IN05]
static inline bool GET_RECOV_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN05]

//>> SET_[RECOV_IN06]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN06]

//>> SET_[RECOV_IN06]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN06]

//>> SET_[RECOV_IN06]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN06]

//>> CLEAR_[RECOV_IN06]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN06]

//>> GET_[RECOV_IN06]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN06]

//>> GET_[RECOV_IN06]
static inline bool GET_RECOV_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN06]

//>> SET_[RECOV_IN07]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN07]

//>> SET_[RECOV_IN07]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN07]

//>> SET_[RECOV_IN07]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN07]

//>> CLEAR_[RECOV_IN07]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN07]

//>> GET_[RECOV_IN07]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN07]

//>> GET_[RECOV_IN07]
static inline bool GET_RECOV_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN07]

//>> SET_[RECOV_IN08]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN08]

//>> SET_[RECOV_IN08]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN08]

//>> SET_[RECOV_IN08]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN08]

//>> CLEAR_[RECOV_IN08]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN08]

//>> GET_[RECOV_IN08]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN08]

//>> GET_[RECOV_IN08]
static inline bool GET_RECOV_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN08]

//>> SET_[RECOV_IN09]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN09]

//>> SET_[RECOV_IN09]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN09]

//>> SET_[RECOV_IN09]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN09]

//>> CLEAR_[RECOV_IN09]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN09]

//>> GET_[RECOV_IN09]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN09]

//>> GET_[RECOV_IN09]
static inline bool GET_RECOV_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN09]

//>> SET_[RECOV_IN10]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN10]

//>> SET_[RECOV_IN10]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN10]

//>> SET_[RECOV_IN10]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN10]

//>> CLEAR_[RECOV_IN10]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN10]

//>> GET_[RECOV_IN10]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN10]

//>> GET_[RECOV_IN10]
static inline bool GET_RECOV_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN10]

//>> SET_[RECOV_IN11]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN11]

//>> SET_[RECOV_IN11]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN11]

//>> SET_[RECOV_IN11]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN11]

//>> CLEAR_[RECOV_IN11]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN11]

//>> GET_[RECOV_IN11]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN11]

//>> GET_[RECOV_IN11]
static inline bool GET_RECOV_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN11]

//>> SET_[RECOV_IN12]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN12]

//>> SET_[RECOV_IN12]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN12]

//>> SET_[RECOV_IN12]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN12]

//>> CLEAR_[RECOV_IN12]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN12]

//>> GET_[RECOV_IN12]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN12]

//>> GET_[RECOV_IN12]
static inline bool GET_RECOV_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN12]

//>> SET_[RECOV_IN13]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN13]

//>> SET_[RECOV_IN13]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN13]

//>> SET_[RECOV_IN13]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN13]

//>> CLEAR_[RECOV_IN13]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN13]

//>> GET_[RECOV_IN13]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN13]

//>> GET_[RECOV_IN13]
static inline bool GET_RECOV_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN13]

//>> SET_[RECOV_IN14]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN14]

//>> SET_[RECOV_IN14]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN14]

//>> SET_[RECOV_IN14]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN14]

//>> CLEAR_[RECOV_IN14]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN14]

//>> GET_[RECOV_IN14]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN14]

//>> GET_[RECOV_IN14]
static inline bool GET_RECOV_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN14]

//>> SET_[RECOV_IN15]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN15]

//>> SET_[RECOV_IN15]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN15]

//>> SET_[RECOV_IN15]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN15]

//>> CLEAR_[RECOV_IN15]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN15]

//>> GET_[RECOV_IN15]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN15]

//>> GET_[RECOV_IN15]
static inline bool GET_RECOV_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN15]

//>> SET_[RECOV_IN16]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN16]

//>> SET_[RECOV_IN16]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN16]

//>> SET_[RECOV_IN16]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN16]

//>> CLEAR_[RECOV_IN16]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN16]

//>> GET_[RECOV_IN16]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN16]

//>> GET_[RECOV_IN16]
static inline bool GET_RECOV_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN16]

//>> SET_[RECOV_IN17]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN17]

//>> SET_[RECOV_IN17]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN17]

//>> SET_[RECOV_IN17]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN17]

//>> CLEAR_[RECOV_IN17]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN17]

//>> GET_[RECOV_IN17]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN17]

//>> GET_[RECOV_IN17]
static inline bool GET_RECOV_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN17]

//>> SET_[RECOV_IN18]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN18]

//>> SET_[RECOV_IN18]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN18]

//>> SET_[RECOV_IN18]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN18]

//>> CLEAR_[RECOV_IN18]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN18]

//>> GET_[RECOV_IN18]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN18]

//>> GET_[RECOV_IN18]
static inline bool GET_RECOV_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN18]

//>> SET_[RECOV_IN19]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN19]

//>> SET_[RECOV_IN19]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN19]

//>> SET_[RECOV_IN19]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN19]

//>> CLEAR_[RECOV_IN19]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN19]

//>> GET_[RECOV_IN19]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN19]

//>> GET_[RECOV_IN19]
static inline bool GET_RECOV_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN19]

//>> SET_[RECOV_IN20]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN20]

//>> SET_[RECOV_IN20]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN20]

//>> SET_[RECOV_IN20]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN20]

//>> CLEAR_[RECOV_IN20]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN20]

//>> GET_[RECOV_IN20]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN20]

//>> GET_[RECOV_IN20]
static inline bool GET_RECOV_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN20]

//>> SET_[RECOV_IN21]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN21]

//>> SET_[RECOV_IN21]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN21]

//>> SET_[RECOV_IN21]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN21]

//>> CLEAR_[RECOV_IN21]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN21]

//>> GET_[RECOV_IN21]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN21]

//>> GET_[RECOV_IN21]
static inline bool GET_RECOV_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN21]

//>> SET_[RECOV_IN22]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN22]

//>> SET_[RECOV_IN22]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN22]

//>> SET_[RECOV_IN22]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN22]

//>> CLEAR_[RECOV_IN22]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN22]

//>> GET_[RECOV_IN22]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN22]

//>> GET_[RECOV_IN22]
static inline bool GET_RECOV_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN22]

//>> SET_[RECOV_IN23]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN23]

//>> SET_[RECOV_IN23]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN23]

//>> SET_[RECOV_IN23]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN23]

//>> CLEAR_[RECOV_IN23]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN23]

//>> GET_[RECOV_IN23]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN23]

//>> GET_[RECOV_IN23]
static inline bool GET_RECOV_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN23]

//>> SET_[RECOV_IN24]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN24]

//>> SET_[RECOV_IN24]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN24]

//>> SET_[RECOV_IN24]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN24]

//>> CLEAR_[RECOV_IN24]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN24]

//>> GET_[RECOV_IN24]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN24]

//>> GET_[RECOV_IN24]
static inline bool GET_RECOV_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN24]

//>> SET_[RECOV_IN25]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN25]

//>> SET_[RECOV_IN25]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN25]

//>> SET_[RECOV_IN25]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN25]

//>> CLEAR_[RECOV_IN25]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN25]

//>> GET_[RECOV_IN25]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN25]

//>> GET_[RECOV_IN25]
static inline bool GET_RECOV_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN25]

//>> SET_[RECOV_IN26]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN26]

//>> SET_[RECOV_IN26]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN26]

//>> SET_[RECOV_IN26]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN26]

//>> CLEAR_[RECOV_IN26]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN26]

//>> GET_[RECOV_IN26]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN26]

//>> GET_[RECOV_IN26]
static inline bool GET_RECOV_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN26]

//>> SET_[RECOV_IN27]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN27]

//>> SET_[RECOV_IN27]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN27]

//>> SET_[RECOV_IN27]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN27]

//>> CLEAR_[RECOV_IN27]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN27]

//>> GET_[RECOV_IN27]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN27]

//>> GET_[RECOV_IN27]
static inline bool GET_RECOV_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN27]

//>> SET_[RECOV_IN28]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN28]

//>> SET_[RECOV_IN28]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN28]

//>> SET_[RECOV_IN28]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN28]

//>> CLEAR_[RECOV_IN28]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN28]

//>> GET_[RECOV_IN28]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN28]

//>> GET_[RECOV_IN28]
static inline bool GET_RECOV_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN28]

//>> SET_[RECOV_IN29]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN29]

//>> SET_[RECOV_IN29]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN29]

//>> SET_[RECOV_IN29]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN29]

//>> CLEAR_[RECOV_IN29]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN29]

//>> GET_[RECOV_IN29]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN29]

//>> GET_[RECOV_IN29]
static inline bool GET_RECOV_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN29]

//>> SET_[RECOV_IN30]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN30]

//>> SET_[RECOV_IN30]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN30]

//>> SET_[RECOV_IN30]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN30]

//>> CLEAR_[RECOV_IN30]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN30]

//>> GET_[RECOV_IN30]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN30]

//>> GET_[RECOV_IN30]
static inline bool GET_RECOV_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN30]

//>> SET_[RECOV_IN31]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN31]

//>> SET_[RECOV_IN31]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN31]

//>> SET_[RECOV_IN31]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN31]

//>> CLEAR_[RECOV_IN31]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN31]

//>> GET_[RECOV_IN31]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN31]

//>> GET_[RECOV_IN31]
static inline bool GET_RECOV_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN31]

//>> SET_[RECOV_IN32]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN32]

//>> SET_[RECOV_IN32]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN32]

//>> SET_[RECOV_IN32]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN32]

//>> CLEAR_[RECOV_IN32]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN32]

//>> GET_[RECOV_IN32]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN32]

//>> GET_[RECOV_IN32]
static inline bool GET_RECOV_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN32]

//>> SET_[RECOV_IN33]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN33]

//>> SET_[RECOV_IN33]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN33]

//>> SET_[RECOV_IN33]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN33]

//>> CLEAR_[RECOV_IN33]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN33]

//>> GET_[RECOV_IN33]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN33]

//>> GET_[RECOV_IN33]
static inline bool GET_RECOV_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN33]

//>> SET_[RECOV_IN34]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN34]

//>> SET_[RECOV_IN34]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN34]

//>> SET_[RECOV_IN34]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN34]

//>> CLEAR_[RECOV_IN34]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN34]

//>> GET_[RECOV_IN34]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN34]

//>> GET_[RECOV_IN34]
static inline bool GET_RECOV_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN34]

//>> SET_[RECOV_IN35]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN35]

//>> SET_[RECOV_IN35]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN35]

//>> SET_[RECOV_IN35]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN35]

//>> CLEAR_[RECOV_IN35]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN35]

//>> GET_[RECOV_IN35]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN35]

//>> GET_[RECOV_IN35]
static inline bool GET_RECOV_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN35]

//>> SET_[RECOV_IN36]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN36]

//>> SET_[RECOV_IN36]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN36]

//>> SET_[RECOV_IN36]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN36]

//>> CLEAR_[RECOV_IN36]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN36]

//>> GET_[RECOV_IN36]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN36]

//>> GET_[RECOV_IN36]
static inline bool GET_RECOV_IN36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN36]

//>> SET_[RECOV_IN37]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN37]

//>> SET_[RECOV_IN37]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN37]

//>> SET_[RECOV_IN37]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN37]

//>> CLEAR_[RECOV_IN37]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN37]

//>> GET_[RECOV_IN37]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN37]

//>> GET_[RECOV_IN37]
static inline bool GET_RECOV_IN37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN37]

//>> SET_[RECOV_IN38]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN38]

//>> SET_[RECOV_IN38]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN38]

//>> SET_[RECOV_IN38]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN38]

//>> CLEAR_[RECOV_IN38]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN38]

//>> GET_[RECOV_IN38]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN38]

//>> GET_[RECOV_IN38]
static inline bool GET_RECOV_IN38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN38]

//>> SET_[RECOV_IN39]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN39]

//>> SET_[RECOV_IN39]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN39]

//>> SET_[RECOV_IN39]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN39]

//>> CLEAR_[RECOV_IN39]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN39]

//>> GET_[RECOV_IN39]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN39]

//>> GET_[RECOV_IN39]
static inline bool GET_RECOV_IN39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN39]

//>> SET_[RECOV_IN40]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN40]

//>> SET_[RECOV_IN40]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN40]

//>> SET_[RECOV_IN40]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN40]

//>> CLEAR_[RECOV_IN40]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN40]

//>> GET_[RECOV_IN40]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN40]

//>> GET_[RECOV_IN40]
static inline bool GET_RECOV_IN40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN40]

//>> SET_[RECOV_IN41]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN41]

//>> SET_[RECOV_IN41]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN41]

//>> SET_[RECOV_IN41]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN41]

//>> CLEAR_[RECOV_IN41]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN41]

//>> GET_[RECOV_IN41]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN41]

//>> GET_[RECOV_IN41]
static inline bool GET_RECOV_IN41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN41]

//>> SET_[RECOV_IN42]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN42]

//>> SET_[RECOV_IN42]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN42]

//>> SET_[RECOV_IN42]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN42]

//>> CLEAR_[RECOV_IN42]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN42]

//>> GET_[RECOV_IN42]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN42]

//>> GET_[RECOV_IN42]
static inline bool GET_RECOV_IN42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN42]

//>> SET_[RECOV_IN43]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN43]

//>> SET_[RECOV_IN43]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN43]

//>> SET_[RECOV_IN43]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN43]

//>> CLEAR_[RECOV_IN43]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN43]

//>> GET_[RECOV_IN43]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN43]

//>> GET_[RECOV_IN43]
static inline bool GET_RECOV_IN43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN43]

//>> SET_[RECOV_IN44]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN44]

//>> SET_[RECOV_IN44]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN44]

//>> SET_[RECOV_IN44]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN44]

//>> CLEAR_[RECOV_IN44]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN44]

//>> GET_[RECOV_IN44]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN44]

//>> GET_[RECOV_IN44]
static inline bool GET_RECOV_IN44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN44]

//>> SET_[RECOV_IN45]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN45]

//>> SET_[RECOV_IN45]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN45]

//>> SET_[RECOV_IN45]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN45]

//>> CLEAR_[RECOV_IN45]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN45]

//>> GET_[RECOV_IN45]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN45]

//>> GET_[RECOV_IN45]
static inline bool GET_RECOV_IN45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN45]

//>> SET_[RECOV_IN46]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN46]

//>> SET_[RECOV_IN46]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN46]

//>> SET_[RECOV_IN46]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN46]

//>> CLEAR_[RECOV_IN46]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN46]

//>> GET_[RECOV_IN46]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN46]

//>> GET_[RECOV_IN46]
static inline bool GET_RECOV_IN46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN46]

//>> SET_[RECOV_IN47]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN47]

//>> SET_[RECOV_IN47]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN47]

//>> SET_[RECOV_IN47]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN47]

//>> CLEAR_[RECOV_IN47]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN47]

//>> GET_[RECOV_IN47]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN47]

//>> GET_[RECOV_IN47]
static inline bool GET_RECOV_IN47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN47]

//>> SET_[RECOV_IN48]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN48]

//>> SET_[RECOV_IN48]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN48]

//>> SET_[RECOV_IN48]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN48]

//>> CLEAR_[RECOV_IN48]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN48]

//>> GET_[RECOV_IN48]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN48]

//>> GET_[RECOV_IN48]
static inline bool GET_RECOV_IN48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN48]

//>> SET_[RECOV_IN49]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN49]

//>> SET_[RECOV_IN49]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN49]

//>> SET_[RECOV_IN49]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN49]

//>> CLEAR_[RECOV_IN49]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN49]

//>> GET_[RECOV_IN49]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN49]

//>> GET_[RECOV_IN49]
static inline bool GET_RECOV_IN49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN49]

//>> SET_[RECOV_IN50]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN50]

//>> SET_[RECOV_IN50]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN50]

//>> SET_[RECOV_IN50]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN50]

//>> CLEAR_[RECOV_IN50]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN50]

//>> GET_[RECOV_IN50]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN50]

//>> GET_[RECOV_IN50]
static inline bool GET_RECOV_IN50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN50]

//>> SET_[RECOV_IN51]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN51]

//>> SET_[RECOV_IN51]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN51]

//>> SET_[RECOV_IN51]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN51]

//>> CLEAR_[RECOV_IN51]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN51]

//>> GET_[RECOV_IN51]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN51]

//>> GET_[RECOV_IN51]
static inline bool GET_RECOV_IN51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN51]

//>> SET_[RECOV_IN52]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN52]

//>> SET_[RECOV_IN52]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN52]

//>> SET_[RECOV_IN52]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN52]

//>> CLEAR_[RECOV_IN52]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN52]

//>> GET_[RECOV_IN52]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN52]

//>> GET_[RECOV_IN52]
static inline bool GET_RECOV_IN52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN52]

//>> SET_[RECOV_IN53]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN53]

//>> SET_[RECOV_IN53]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.insertFromRight<RECOV_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN53]

//>> SET_[RECOV_IN53]
static inline fapi2::buffer<uint64_t>& SET_RECOV_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.setBit<RECOV_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_IN53]

//>> CLEAR_[RECOV_IN53]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return o_data.clearBit<RECOV_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_IN53]

//>> GET_[RECOV_IN53]
static inline fapi2::buffer<uint64_t>& GET_RECOV_IN53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.extractToRight<RECOV_IN53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN53]

//>> GET_[RECOV_IN53]
static inline bool GET_RECOV_IN53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV));
#endif
    return i_data.getBit<RECOV_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access RECOV_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_IN53]

//>> PREP_[SCOMFIR_MCFGP0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFGP0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFGP0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCFGP0]

//>> GET_[SCOMFIR_MCFGP0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFGP0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFGP0;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFGP0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCFGP0]

//>> PUT_[SCOMFIR_MCFGP0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFGP0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFGP0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCFGP0]


//>> SET_[SCOMFIR_MCFGP0_0_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_VALID]

//>> SET_[SCOMFIR_MCFGP0_0_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_VALID]

//>> SET_[SCOMFIR_MCFGP0_0_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.setBit<SCOMFIR_MCFGP0_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_VALID]

//>> CLEAR_[SCOMFIR_MCFGP0_0_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.clearBit<SCOMFIR_MCFGP0_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFGP0_0_VALID]

//>> GET_[SCOMFIR_MCFGP0_0_VALID]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP0_0_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP0_0_VALID]

//>> GET_[SCOMFIR_MCFGP0_0_VALID]
static inline bool GET_SCOMFIR_MCFGP0_0_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return i_data.getBit<SCOMFIR_MCFGP0_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP0_0_VALID]

//>> SET_[SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS,
           SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS]

//>> SET_[SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS,
           SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS]

//>> GET_[SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS,
           SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS]

//>> SET_[SCOMFIR_MCFGP0_0_GROUP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_GROUP_SIZE,
           SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_GROUP_SIZE]

//>> SET_[SCOMFIR_MCFGP0_0_GROUP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_GROUP_SIZE,
           SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_GROUP_SIZE]

//>> GET_[SCOMFIR_MCFGP0_0_GROUP_SIZE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP0_0_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP0_0_GROUP_SIZE,
           SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP0_0_GROUP_SIZE]

//>> SET_[SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP,
           SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP]

//>> SET_[SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP,
           SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP]

//>> GET_[SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP,
           SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP]

//>> SET_[SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION,
           SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION]

//>> SET_[SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION,
           SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION]

//>> GET_[SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION,
           SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION]

//>> SET_[SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE,
           SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE]

//>> SET_[SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE,
           SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE]

//>> GET_[SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE,
           SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE]

//>> SET_[SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE,
           SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE]

//>> SET_[SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE,
           SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE]

//>> GET_[SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFGP0));
#endif
    return i_data.extractToRight<SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE,
           SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE]

//>> PREP_[XSTOP4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP4]

//>> GET_[XSTOP4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP4(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP4;
#endif
    return fapi2::getScom(i_target, XSTOP4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP4]

//>> PUT_[XSTOP4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return fapi2::putScom(i_target, XSTOP4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP4]


//>> SET_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_ENABLE]

//>> SET_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_ENABLE]

//>> SET_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_ENABLE]

//>> CLEAR_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_ENABLE]

//>> GET_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_ENABLE]

//>> GET_[XSTOP4_ENABLE]
static inline bool GET_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_ENABLE]

//>> SET_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_SNOPA]

//>> SET_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_SNOPA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_SNOPA]

//>> SET_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_SNOPA]

//>> CLEAR_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_WAIT_SNOPA]

//>> GET_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_WAIT_SNOPA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_SNOPA]

//>> GET_[XSTOP4_WAIT_SNOPA]
static inline bool GET_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_SNOPA]

//>> SET_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_TRIGGER_OPCG_GO]

//>> SET_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_TRIGGER_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_TRIGGER_OPCG_GO]

//>> SET_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_TRIGGER_OPCG_GO]

//>> CLEAR_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_TRIGGER_OPCG_GO]

//>> GET_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_TRIGGER_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_TRIGGER_OPCG_GO]

//>> GET_[XSTOP4_TRIGGER_OPCG_GO]
static inline bool GET_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_TRIGGER_OPCG_GO]

//>> SET_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_ALWAYS]

//>> SET_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_ALWAYS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_ALWAYS]

//>> SET_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_ALWAYS]

//>> CLEAR_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_WAIT_ALWAYS]

//>> GET_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_WAIT_ALWAYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_ALWAYS]

//>> GET_[XSTOP4_WAIT_ALWAYS]
static inline bool GET_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_ALWAYS]

//>> SET_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_PERV]

//>> SET_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_PERV]

//>> SET_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_PERV]

//>> CLEAR_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_PERV]

//>> GET_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_PERV]

//>> GET_[XSTOP4_REGION_PERV]
static inline bool GET_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_PERV]

//>> SET_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT1]

//>> SET_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT1]

//>> SET_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT1]

//>> CLEAR_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT1]

//>> GET_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT1]

//>> GET_[XSTOP4_REGION_UNIT1]
static inline bool GET_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT1]

//>> SET_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT2]

//>> SET_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT2]

//>> SET_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT2]

//>> CLEAR_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT2]

//>> GET_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT2]

//>> GET_[XSTOP4_REGION_UNIT2]
static inline bool GET_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT2]

//>> SET_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT3]

//>> SET_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT3]

//>> SET_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT3]

//>> CLEAR_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT3]

//>> GET_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT3]

//>> GET_[XSTOP4_REGION_UNIT3]
static inline bool GET_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT3]

//>> SET_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT4]

//>> SET_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT4]

//>> SET_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT4]

//>> CLEAR_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT4]

//>> GET_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT4]

//>> GET_[XSTOP4_REGION_UNIT4]
static inline bool GET_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT4]

//>> SET_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT5]

//>> SET_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT5]

//>> SET_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT5]

//>> CLEAR_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT5]

//>> GET_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT5]

//>> GET_[XSTOP4_REGION_UNIT5]
static inline bool GET_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT5]

//>> SET_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT6]

//>> SET_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT6]

//>> SET_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT6]

//>> CLEAR_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT6]

//>> GET_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT6]

//>> GET_[XSTOP4_REGION_UNIT6]
static inline bool GET_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT6]

//>> SET_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT7]

//>> SET_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT7]

//>> SET_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT7]

//>> CLEAR_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT7]

//>> GET_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT7]

//>> GET_[XSTOP4_REGION_UNIT7]
static inline bool GET_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT7]

//>> SET_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT8]

//>> SET_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT8]

//>> SET_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT8]

//>> CLEAR_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT8]

//>> GET_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT8]

//>> GET_[XSTOP4_REGION_UNIT8]
static inline bool GET_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT8]

//>> SET_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT9]

//>> SET_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT9]

//>> SET_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT9]

//>> CLEAR_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT9]

//>> GET_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT9]

//>> GET_[XSTOP4_REGION_UNIT9]
static inline bool GET_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT9]

//>> SET_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT10]

//>> SET_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT10]

//>> SET_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT10]

//>> CLEAR_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT10]

//>> GET_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT10]

//>> GET_[XSTOP4_REGION_UNIT10]
static inline bool GET_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT10]

//>> SET_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT11]

//>> SET_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT11]

//>> SET_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT11]

//>> CLEAR_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT11]

//>> GET_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT11]

//>> GET_[XSTOP4_REGION_UNIT11]
static inline bool GET_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT11]

//>> SET_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT12]

//>> SET_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT12]

//>> SET_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT12]

//>> CLEAR_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT12]

//>> GET_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT12]

//>> GET_[XSTOP4_REGION_UNIT12]
static inline bool GET_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT12]

//>> SET_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT13]

//>> SET_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT13]

//>> SET_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT13]

//>> CLEAR_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT13]

//>> GET_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT13]

//>> GET_[XSTOP4_REGION_UNIT13]
static inline bool GET_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT13]

//>> SET_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT14]

//>> SET_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT14]

//>> SET_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT14]

//>> CLEAR_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT14]

//>> GET_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT14]

//>> GET_[XSTOP4_REGION_UNIT14]
static inline bool GET_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT14]

//>> SET_[XSTOP4_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_CYCLES,
           XSTOP4_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access XSTOP4_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_CYCLES]

//>> SET_[XSTOP4_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_CYCLES,
           XSTOP4_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access XSTOP4_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_CYCLES]

//>> GET_[XSTOP4_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_WAIT_CYCLES,
           XSTOP4_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access XSTOP4_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_CYCLES]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
