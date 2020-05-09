/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00014.H $            */
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

#ifndef __C_REG00014_H_
#define __C_REG00014_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[ATOMIC_LOCK_MASK_LATCH_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATOMIC_LOCK_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATOMIC_LOCK_MASK_LATCH_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ATOMIC_LOCK_MASK_LATCH_REG]

//>> GET_[ATOMIC_LOCK_MASK_LATCH_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATOMIC_LOCK_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATOMIC_LOCK_MASK_LATCH_REG;
#endif
    return fapi2::getScom(i_target, ATOMIC_LOCK_MASK_LATCH_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ATOMIC_LOCK_MASK_LATCH_REG]

//>> PUT_[ATOMIC_LOCK_MASK_LATCH_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATOMIC_LOCK_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_MASK_LATCH_REG));
#endif
    return fapi2::putScom(i_target, ATOMIC_LOCK_MASK_LATCH_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ATOMIC_LOCK_MASK_LATCH_REG]


//>> SET_[ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK,
           ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK]

//>> SET_[ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK]
static inline fapi2::buffer<uint64_t>& SET_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK,
           ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK]

//>> GET_[ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK]
static inline fapi2::buffer<uint64_t>& GET_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATOMIC_LOCK_MASK_LATCH_REG));
#endif
    return i_data.extractToRight<ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK,
           ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK]

//>> PREP_[CPMS_ASSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_ASSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_ASSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_ASSR]

//>> GET_[CPMS_ASSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_ASSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_ASSR;
#endif
    return fapi2::getScom(i_target, CPMS_ASSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_ASSR]

//>> PUT_[CPMS_ASSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_ASSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return fapi2::putScom(i_target, CPMS_ASSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_ASSR]


//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]

//>> SET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]

//>> SET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]

//>> CLEAR_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]

//>> GET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]

//>> GET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]
static inline bool GET_CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE]

//>> SET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]

//>> SET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]

//>> SET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]

//>> CLEAR_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]

//>> GET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]

//>> GET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]
static inline bool GET_CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> CLEAR_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline bool GET_CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> CLEAR_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline bool GET_CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_ASSR_L3_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_L3_CLKGLM_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_L3_CLKGLM_SEL]

//>> SET_[CPMS_ASSR_L3_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_L3_CLKGLM_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_L3_CLKGLM_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_L3_CLKGLM_SEL]

//>> SET_[CPMS_ASSR_L3_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_L3_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_L3_CLKGLM_SEL]

//>> CLEAR_[CPMS_ASSR_L3_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_L3_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_L3_CLKGLM_SEL]

//>> GET_[CPMS_ASSR_L3_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_L3_CLKGLM_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_L3_CLKGLM_SEL]

//>> GET_[CPMS_ASSR_L3_CLKGLM_SEL]
static inline bool GET_CPMS_ASSR_L3_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_L3_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_L3_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_L3_CLKGLM_SEL]

//>> SET_[CPMS_ASSR_L2_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_L2_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_L2_CLKGLM_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_L2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_L2_CLKGLM_SEL]

//>> SET_[CPMS_ASSR_L2_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_L2_CLKGLM_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_L2_CLKGLM_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_L2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_L2_CLKGLM_SEL]

//>> SET_[CPMS_ASSR_L2_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_L2_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_L2_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_L2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_L2_CLKGLM_SEL]

//>> CLEAR_[CPMS_ASSR_L2_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_L2_CLKGLM_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_L2_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_L2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_L2_CLKGLM_SEL]

//>> GET_[CPMS_ASSR_L2_CLKGLM_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_L2_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_L2_CLKGLM_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_L2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_L2_CLKGLM_SEL]

//>> GET_[CPMS_ASSR_L2_CLKGLM_SEL]
static inline bool GET_CPMS_ASSR_L2_CLKGLM_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_L2_CLKGLM_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_L2_CLKGLM_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_L2_CLKGLM_SEL]

//>> SET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> SET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> SET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> CLEAR_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> GET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> GET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]
static inline bool GET_CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE]

//>> SET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> SET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> SET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.setBit<CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> CLEAR_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.clearBit<CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> GET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> GET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]
static inline bool GET_CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.getBit<CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_AVG]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_AVG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_AVG,
           CPMS_ASSR_CL2_VDD_CURRENT_AVG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_AVG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_AVG]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_AVG]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_AVG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_AVG,
           CPMS_ASSR_CL2_VDD_CURRENT_AVG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_AVG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_AVG]

//>> GET_[CPMS_ASSR_CL2_VDD_CURRENT_AVG]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CL2_VDD_CURRENT_AVG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CL2_VDD_CURRENT_AVG,
           CPMS_ASSR_CL2_VDD_CURRENT_AVG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_AVG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CL2_VDD_CURRENT_AVG]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE0]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE0,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE0]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE0]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE0,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE0]

//>> GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE0]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE0,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE0]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE1]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE1,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE1]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE1]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE1,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE1]

//>> GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE1]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE1,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE1]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE2]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE2,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE2]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE2]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE2,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE2]

//>> GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE2]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE2,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE2]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE3]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE3,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE3]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE3]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE3,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE3]

//>> GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE3]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE3,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE3]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX]

//>> GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN]

//>> SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return o_data.insertFromRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN]

//>> GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_ASSR));
#endif
    return i_data.extractToRight<CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN,
           CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN]

//>> PREP_[CPMS_DESR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DESR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DESR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DESR]

//>> GET_[CPMS_DESR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DESR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DESR;
#endif
    return fapi2::getScom(i_target, CPMS_DESR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DESR]

//>> PUT_[CPMS_DESR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DESR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return fapi2::putScom(i_target, CPMS_DESR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DESR]


//>> SET_[CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL,
           CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL]

//>> SET_[CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL,
           CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL]

//>> GET_[CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL,
           CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL]

//>> SET_[CPMS_DESR_COUNTA_FTC_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTA_FTC_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTA_FTC_EVENT_SEL,
           CPMS_DESR_COUNTA_FTC_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_COUNTA_FTC_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTA_FTC_EVENT_SEL]

//>> SET_[CPMS_DESR_COUNTA_FTC_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTA_FTC_EVENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTA_FTC_EVENT_SEL,
           CPMS_DESR_COUNTA_FTC_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_COUNTA_FTC_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTA_FTC_EVENT_SEL]

//>> GET_[CPMS_DESR_COUNTA_FTC_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_COUNTA_FTC_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_COUNTA_FTC_EVENT_SEL,
           CPMS_DESR_COUNTA_FTC_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_COUNTA_FTC_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_COUNTA_FTC_EVENT_SEL]

//>> SET_[CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL,
           CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL]

//>> SET_[CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL,
           CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL]

//>> GET_[CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL,
           CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL]

//>> SET_[CPMS_DESR_COUNTB_FTC_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTB_FTC_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTB_FTC_EVENT_SEL,
           CPMS_DESR_COUNTB_FTC_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_COUNTB_FTC_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTB_FTC_EVENT_SEL]

//>> SET_[CPMS_DESR_COUNTB_FTC_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTB_FTC_EVENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTB_FTC_EVENT_SEL,
           CPMS_DESR_COUNTB_FTC_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_COUNTB_FTC_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTB_FTC_EVENT_SEL]

//>> GET_[CPMS_DESR_COUNTB_FTC_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_COUNTB_FTC_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_COUNTB_FTC_EVENT_SEL,
           CPMS_DESR_COUNTB_FTC_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_COUNTB_FTC_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_COUNTB_FTC_EVENT_SEL]

//>> SET_[CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL,
           CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL]

//>> SET_[CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL,
           CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL]

//>> GET_[CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL,
           CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL]

//>> SET_[CPMS_DESR_COUNTC_FTC_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTC_FTC_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTC_FTC_EVENT_SEL,
           CPMS_DESR_COUNTC_FTC_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_COUNTC_FTC_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTC_FTC_EVENT_SEL]

//>> SET_[CPMS_DESR_COUNTC_FTC_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTC_FTC_EVENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTC_FTC_EVENT_SEL,
           CPMS_DESR_COUNTC_FTC_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_COUNTC_FTC_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTC_FTC_EVENT_SEL]

//>> GET_[CPMS_DESR_COUNTC_FTC_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_COUNTC_FTC_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_COUNTC_FTC_EVENT_SEL,
           CPMS_DESR_COUNTC_FTC_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_COUNTC_FTC_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_COUNTC_FTC_EVENT_SEL]

//>> SET_[CPMS_DESR_COUNTA_FTC_STATE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTA_FTC_STATE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTA_FTC_STATE_SELECT,
           CPMS_DESR_COUNTA_FTC_STATE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_COUNTA_FTC_STATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTA_FTC_STATE_SELECT]

//>> SET_[CPMS_DESR_COUNTA_FTC_STATE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTA_FTC_STATE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTA_FTC_STATE_SELECT,
           CPMS_DESR_COUNTA_FTC_STATE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_COUNTA_FTC_STATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTA_FTC_STATE_SELECT]

//>> GET_[CPMS_DESR_COUNTA_FTC_STATE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_COUNTA_FTC_STATE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_COUNTA_FTC_STATE_SELECT,
           CPMS_DESR_COUNTA_FTC_STATE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_COUNTA_FTC_STATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_COUNTA_FTC_STATE_SELECT]

//>> SET_[CPMS_DESR_COUNTB_FTC_STATE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTB_FTC_STATE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTB_FTC_STATE_SELECT,
           CPMS_DESR_COUNTB_FTC_STATE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_COUNTB_FTC_STATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTB_FTC_STATE_SELECT]

//>> SET_[CPMS_DESR_COUNTB_FTC_STATE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTB_FTC_STATE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTB_FTC_STATE_SELECT,
           CPMS_DESR_COUNTB_FTC_STATE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_COUNTB_FTC_STATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTB_FTC_STATE_SELECT]

//>> GET_[CPMS_DESR_COUNTB_FTC_STATE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_COUNTB_FTC_STATE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_COUNTB_FTC_STATE_SELECT,
           CPMS_DESR_COUNTB_FTC_STATE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_COUNTB_FTC_STATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_COUNTB_FTC_STATE_SELECT]

//>> SET_[CPMS_DESR_COUNTC_FTC_STATE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTC_FTC_STATE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTC_FTC_STATE_SELECT,
           CPMS_DESR_COUNTC_FTC_STATE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_COUNTC_FTC_STATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTC_FTC_STATE_SELECT]

//>> SET_[CPMS_DESR_COUNTC_FTC_STATE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_COUNTC_FTC_STATE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_COUNTC_FTC_STATE_SELECT,
           CPMS_DESR_COUNTC_FTC_STATE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_COUNTC_FTC_STATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_COUNTC_FTC_STATE_SELECT]

//>> GET_[CPMS_DESR_COUNTC_FTC_STATE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_COUNTC_FTC_STATE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_COUNTC_FTC_STATE_SELECT,
           CPMS_DESR_COUNTC_FTC_STATE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_COUNTC_FTC_STATE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_COUNTC_FTC_STATE_SELECT]

//>> SET_[CPMS_DESR_FTC_INVERT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_FTC_INVERT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_FTC_INVERT_SEL,
           CPMS_DESR_FTC_INVERT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_FTC_INVERT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_FTC_INVERT_SEL]

//>> SET_[CPMS_DESR_FTC_INVERT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_FTC_INVERT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_FTC_INVERT_SEL,
           CPMS_DESR_FTC_INVERT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_FTC_INVERT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_FTC_INVERT_SEL]

//>> GET_[CPMS_DESR_FTC_INVERT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_FTC_INVERT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_FTC_INVERT_SEL,
           CPMS_DESR_FTC_INVERT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_FTC_INVERT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_FTC_INVERT_SEL]

//>> SET_[CPMS_DESR_FTC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_FTC_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_FTC_SPARE,
           CPMS_DESR_FTC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_FTC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_FTC_SPARE]

//>> SET_[CPMS_DESR_FTC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_FTC_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_FTC_SPARE,
           CPMS_DESR_FTC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_FTC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_FTC_SPARE]

//>> GET_[CPMS_DESR_FTC_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_FTC_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_FTC_SPARE,
           CPMS_DESR_FTC_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_FTC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_FTC_SPARE]

//>> SET_[CPMS_DESR_FTC_EVENT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_FTC_EVENT_INVERT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_FTC_EVENT_INVERT,
           CPMS_DESR_FTC_EVENT_INVERT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_FTC_EVENT_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_FTC_EVENT_INVERT]

//>> SET_[CPMS_DESR_FTC_EVENT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_FTC_EVENT_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_FTC_EVENT_INVERT,
           CPMS_DESR_FTC_EVENT_INVERT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_FTC_EVENT_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_FTC_EVENT_INVERT]

//>> GET_[CPMS_DESR_FTC_EVENT_INVERT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_FTC_EVENT_INVERT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_FTC_EVENT_INVERT,
           CPMS_DESR_FTC_EVENT_INVERT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_FTC_EVENT_INVERT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_FTC_EVENT_INVERT]

//>> SET_[CPMS_DESR_STATEW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_STATEW_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_STATEW_ENABLE,
           CPMS_DESR_STATEW_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_STATEW_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_STATEW_ENABLE]

//>> SET_[CPMS_DESR_STATEW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_STATEW_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_STATEW_ENABLE,
           CPMS_DESR_STATEW_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_STATEW_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_STATEW_ENABLE]

//>> GET_[CPMS_DESR_STATEW_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_STATEW_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_STATEW_ENABLE,
           CPMS_DESR_STATEW_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_STATEW_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_STATEW_ENABLE]

//>> SET_[CPMS_DESR_STATEZ_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_STATEZ_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_STATEZ_ENABLE,
           CPMS_DESR_STATEZ_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_STATEZ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_STATEZ_ENABLE]

//>> SET_[CPMS_DESR_STATEZ_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_STATEZ_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_STATEZ_ENABLE,
           CPMS_DESR_STATEZ_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_STATEZ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_STATEZ_ENABLE]

//>> GET_[CPMS_DESR_STATEZ_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_STATEZ_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_STATEZ_ENABLE,
           CPMS_DESR_STATEZ_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_STATEZ_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_STATEZ_ENABLE]

//>> SET_[CPMS_DESR_SPARE_COUNT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_SPARE_COUNT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_SPARE_COUNT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_SPARE_COUNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_SPARE_COUNT_SEL]

//>> SET_[CPMS_DESR_SPARE_COUNT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_SPARE_COUNT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_SPARE_COUNT_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_SPARE_COUNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_SPARE_COUNT_SEL]

//>> SET_[CPMS_DESR_SPARE_COUNT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_SPARE_COUNT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.setBit<CPMS_DESR_SPARE_COUNT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DESR_SPARE_COUNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_SPARE_COUNT_SEL]

//>> CLEAR_[CPMS_DESR_SPARE_COUNT_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DESR_SPARE_COUNT_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.clearBit<CPMS_DESR_SPARE_COUNT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DESR_SPARE_COUNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DESR_SPARE_COUNT_SEL]

//>> GET_[CPMS_DESR_SPARE_COUNT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_SPARE_COUNT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_SPARE_COUNT_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_SPARE_COUNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_SPARE_COUNT_SEL]

//>> GET_[CPMS_DESR_SPARE_COUNT_SEL]
static inline bool GET_CPMS_DESR_SPARE_COUNT_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.getBit<CPMS_DESR_SPARE_COUNT_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DESR_SPARE_COUNT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_SPARE_COUNT_SEL]

//>> SET_[CPMS_DESR_SECONDARY_QUAL_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_SECONDARY_QUAL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_SECONDARY_QUAL_SEL,
           CPMS_DESR_SECONDARY_QUAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_SECONDARY_QUAL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_SECONDARY_QUAL_SEL]

//>> SET_[CPMS_DESR_SECONDARY_QUAL_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_SECONDARY_QUAL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_SECONDARY_QUAL_SEL,
           CPMS_DESR_SECONDARY_QUAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_SECONDARY_QUAL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_SECONDARY_QUAL_SEL]

//>> GET_[CPMS_DESR_SECONDARY_QUAL_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_SECONDARY_QUAL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_SECONDARY_QUAL_SEL,
           CPMS_DESR_SECONDARY_QUAL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_SECONDARY_QUAL_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_SECONDARY_QUAL_SEL]

//>> SET_[CPMS_DESR_SECONDARY_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_SECONDARY_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_SECONDARY_EVENT_SEL,
           CPMS_DESR_SECONDARY_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DESR_SECONDARY_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_SECONDARY_EVENT_SEL]

//>> SET_[CPMS_DESR_SECONDARY_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DESR_SECONDARY_EVENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return o_data.insertFromRight<CPMS_DESR_SECONDARY_EVENT_SEL,
           CPMS_DESR_SECONDARY_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DESR_SECONDARY_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DESR_SECONDARY_EVENT_SEL]

//>> GET_[CPMS_DESR_SECONDARY_EVENT_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DESR_SECONDARY_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DESR));
#endif
    return i_data.extractToRight<CPMS_DESR_SECONDARY_EVENT_SEL,
           CPMS_DESR_SECONDARY_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DESR_SECONDARY_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DESR_SECONDARY_EVENT_SEL]

//>> PREP_[CPMS_DTTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DTTR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DTTR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DTTR]

//>> GET_[CPMS_DTTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DTTR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DTTR;
#endif
    return fapi2::getScom(i_target, CPMS_DTTR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DTTR]

//>> PUT_[CPMS_DTTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DTTR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return fapi2::putScom(i_target, CPMS_DTTR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DTTR]


//>> SET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT,
           CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT]

//>> SET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT,
           CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT]

//>> GET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return i_data.extractToRight<CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT,
           CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT]

//>> SET_[CPMS_DTTR_T1_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T1_DPT_RATE_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T1_DPT_RATE_LIMIT,
           CPMS_DTTR_T1_DPT_RATE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTTR_T1_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T1_DPT_RATE_LIMIT]

//>> SET_[CPMS_DTTR_T1_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T1_DPT_RATE_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T1_DPT_RATE_LIMIT,
           CPMS_DTTR_T1_DPT_RATE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTTR_T1_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T1_DPT_RATE_LIMIT]

//>> GET_[CPMS_DTTR_T1_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTTR_T1_DPT_RATE_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return i_data.extractToRight<CPMS_DTTR_T1_DPT_RATE_LIMIT,
           CPMS_DTTR_T1_DPT_RATE_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTTR_T1_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTTR_T1_DPT_RATE_LIMIT]

//>> SET_[CPMS_DTTR_T2_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T2_DPT_RATE_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T2_DPT_RATE_LIMIT,
           CPMS_DTTR_T2_DPT_RATE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTTR_T2_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T2_DPT_RATE_LIMIT]

//>> SET_[CPMS_DTTR_T2_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T2_DPT_RATE_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T2_DPT_RATE_LIMIT,
           CPMS_DTTR_T2_DPT_RATE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTTR_T2_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T2_DPT_RATE_LIMIT]

//>> GET_[CPMS_DTTR_T2_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTTR_T2_DPT_RATE_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return i_data.extractToRight<CPMS_DTTR_T2_DPT_RATE_LIMIT,
           CPMS_DTTR_T2_DPT_RATE_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTTR_T2_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTTR_T2_DPT_RATE_LIMIT]

//>> SET_[CPMS_DTTR_T3_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T3_DPT_RATE_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T3_DPT_RATE_LIMIT,
           CPMS_DTTR_T3_DPT_RATE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTTR_T3_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T3_DPT_RATE_LIMIT]

//>> SET_[CPMS_DTTR_T3_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T3_DPT_RATE_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T3_DPT_RATE_LIMIT,
           CPMS_DTTR_T3_DPT_RATE_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTTR_T3_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T3_DPT_RATE_LIMIT]

//>> GET_[CPMS_DTTR_T3_DPT_RATE_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTTR_T3_DPT_RATE_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return i_data.extractToRight<CPMS_DTTR_T3_DPT_RATE_LIMIT,
           CPMS_DTTR_T3_DPT_RATE_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTTR_T3_DPT_RATE_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTTR_T3_DPT_RATE_LIMIT]

//>> SET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT]

//>> SET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT]

//>> GET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return i_data.extractToRight<CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT]

//>> SET_[CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT]

//>> SET_[CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT]

//>> GET_[CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return i_data.extractToRight<CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT]

//>> SET_[CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT]

//>> SET_[CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT]

//>> GET_[CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return i_data.extractToRight<CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT]

//>> SET_[CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT]

//>> SET_[CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return o_data.insertFromRight<CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT]

//>> GET_[CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DTTR));
#endif
    return i_data.extractToRight<CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT,
           CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT]

//>> PREP_[EC_LS_LSU_HOLD_OUT_REG12]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG12(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG12;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_LS_LSU_HOLD_OUT_REG12]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG12(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG12;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG12, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12]

//>> PUT_[EC_LS_LSU_HOLD_OUT_REG12]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG12(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG12, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_LS_LSU_HOLD_OUT_REG12]


//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S0_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_ALLOC_COLLISION_ON_NON_DERAT_OP_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_BOTH_SRQZ_HAS_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_NON_OW_STORE_HAS_MULTIPLE_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_S1_OW_STORE_HAS_TOO_MANY_DATA_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_RES_FM_VIOLATION_WITH_MV_HIT_ERR_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
CLEAR_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L0_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_FINAL_PASS_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_LD_OP_UNEXPECTED_FINISH_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>&
CLEAR_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG12));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG12_L1_FLS_SECURITY_LD_FINISH_W_EXCPT_AND_DVAL_HOLD_OUT]

//>> PREP_[EC_LS_LSU_HOLD_OUT_REG4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_LS_LSU_HOLD_OUT_REG4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG4;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4]

//>> PUT_[EC_LS_LSU_HOLD_OUT_REG4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_LS_LSU_HOLD_OUT_REG4]


//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_MP3_RADA_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG4));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG4_RC5_SNOOP_RADA_ERR_HOLD_OUT_SET7]

//>> PREP_[EC_PC_PMC_CORE_THREAD_STATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PMC_CORE_THREAD_STATE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMC_CORE_THREAD_STATE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_PMC_CORE_THREAD_STATE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PMC_CORE_THREAD_STATE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMC_CORE_THREAD_STATE;
#endif
    return fapi2::getScom(i_target, EC_PC_PMC_CORE_THREAD_STATE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE]

//>> PUT_[EC_PC_PMC_CORE_THREAD_STATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PMC_CORE_THREAD_STATE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return fapi2::putScom(i_target, EC_PC_PMC_CORE_THREAD_STATE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_PMC_CORE_THREAD_STATE]


//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_PSSCR_RL]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_PSSCR_RL]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_PSSCR_RL]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL,
           EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_PSSCR_RL]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.setBit<EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]

//>> CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.clearBit<EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]
static inline bool GET_EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.getBit<EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT0_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.setBit<EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]

//>> CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.clearBit<EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]
static inline bool GET_EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.getBit<EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT1_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.setBit<EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]

//>> CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.clearBit<EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]
static inline bool GET_EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.getBit<EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT2_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.setBit<EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]

//>> CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.clearBit<EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]
static inline bool GET_EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.getBit<EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_VT3_STOP_STATE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.setBit<EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]

//>> CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.clearBit<EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]
static inline bool GET_EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.getBit<EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_LPAR_MODE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]

//>> SET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.setBit<EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]

//>> CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return o_data.clearBit<EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]

//>> GET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]
static inline bool GET_EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_CORE_THREAD_STATE));
#endif
    return i_data.getBit<EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_CORE_THREAD_STATE_FUSED_CORE_MODE]

//>> PREP_[EC_PC_PMU_SPRCOR_OCC_SCOMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PMU_SPRCOR_OCC_SCOMD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_OCC_SCOMD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_PMU_SPRCOR_OCC_SCOMD]

//>> GET_[EC_PC_PMU_SPRCOR_OCC_SCOMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PMU_SPRCOR_OCC_SCOMD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_OCC_SCOMD;
#endif
    return fapi2::getScom(i_target, EC_PC_PMU_SPRCOR_OCC_SCOMD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_OCC_SCOMD]

//>> PUT_[EC_PC_PMU_SPRCOR_OCC_SCOMD]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PMU_SPRCOR_OCC_SCOMD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_OCC_SCOMD));
#endif
    return fapi2::putScom(i_target, EC_PC_PMU_SPRCOR_OCC_SCOMD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_PMU_SPRCOR_OCC_SCOMD]


//>> PREP_[EC_PC_SCR6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SCR6(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR6;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_SCR6]

//>> GET_[EC_PC_SCR6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SCR6(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR6;
#endif
    return fapi2::getScom(i_target, EC_PC_SCR6, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_SCR6]

//>> PUT_[EC_PC_SCR6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SCR6(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SCR6));
#endif
    return fapi2::putScom(i_target, EC_PC_SCR6, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_SCR6]


//>> PREP_[EC_PC_TRACE2_TR_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE2_TR_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE2_TR_TR0_CONFIG_4]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE2_TR_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE2_TR_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_4]

//>> PUT_[EC_PC_TRACE2_TR_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE2_TR_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE2_TR_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE2_TR_TR0_CONFIG_4]


//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_4_A,
           EC_PC_TRACE2_TR_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_A]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_4_A,
           EC_PC_TRACE2_TR_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_A]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_CONFIG_4_A,
           EC_PC_TRACE2_TR_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_A]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_4_B,
           EC_PC_TRACE2_TR_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_B]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_4_B,
           EC_PC_TRACE2_TR_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_B]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_CONFIG_4_B,
           EC_PC_TRACE2_TR_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_4_B]

//>> PREP_[L2_L2MISC_L2CERRS_TOPOTABLE1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_TOPOTABLE1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_TOPOTABLE1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_TOPOTABLE1]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_TOPOTABLE1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_TOPOTABLE1;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_TOPOTABLE1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1]

//>> PUT_[L2_L2MISC_L2CERRS_TOPOTABLE1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_TOPOTABLE1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_TOPOTABLE1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_TOPOTABLE1]


//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]

//>> CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]
static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_08,
           L2_L2MISC_L2CERRS_TOPOTABLE1_08_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_08,
           L2_L2MISC_L2CERRS_TOPOTABLE1_08_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_08,
           L2_L2MISC_L2CERRS_TOPOTABLE1_08_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_08]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_09,
           L2_L2MISC_L2CERRS_TOPOTABLE1_09_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_09,
           L2_L2MISC_L2CERRS_TOPOTABLE1_09_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_09,
           L2_L2MISC_L2CERRS_TOPOTABLE1_09_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_09]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_10,
           L2_L2MISC_L2CERRS_TOPOTABLE1_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_10,
           L2_L2MISC_L2CERRS_TOPOTABLE1_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_10,
           L2_L2MISC_L2CERRS_TOPOTABLE1_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_10]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_11,
           L2_L2MISC_L2CERRS_TOPOTABLE1_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_11,
           L2_L2MISC_L2CERRS_TOPOTABLE1_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_11,
           L2_L2MISC_L2CERRS_TOPOTABLE1_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_11]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_12,
           L2_L2MISC_L2CERRS_TOPOTABLE1_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_12,
           L2_L2MISC_L2CERRS_TOPOTABLE1_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_12,
           L2_L2MISC_L2CERRS_TOPOTABLE1_12_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_12]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_13,
           L2_L2MISC_L2CERRS_TOPOTABLE1_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_13,
           L2_L2MISC_L2CERRS_TOPOTABLE1_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_13,
           L2_L2MISC_L2CERRS_TOPOTABLE1_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_13]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_14,
           L2_L2MISC_L2CERRS_TOPOTABLE1_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_14,
           L2_L2MISC_L2CERRS_TOPOTABLE1_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_14,
           L2_L2MISC_L2CERRS_TOPOTABLE1_14_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_14]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_15,
           L2_L2MISC_L2CERRS_TOPOTABLE1_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15]

//>> SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE1_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE1_15,
           L2_L2MISC_L2CERRS_TOPOTABLE1_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15]

//>> GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE1_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE1_15,
           L2_L2MISC_L2CERRS_TOPOTABLE1_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE1_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_TOPOTABLE1_15]

//>> PREP_[L2TRA_TR0_CONFIG_9]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR0_CONFIG_9]

//>> GET_[L2TRA_TR0_CONFIG_9]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_9;
#endif
    return fapi2::getScom(i_target, L2TRA_TR0_CONFIG_9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9]

//>> PUT_[L2TRA_TR0_CONFIG_9]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return fapi2::putScom(i_target, L2TRA_TR0_CONFIG_9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR0_CONFIG_9]


//>> SET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> SET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> SET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> GET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> GET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline bool GET_L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> SET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> GET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> GET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline bool GET_L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL]

//>> GET_[L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL]

//>> GET_[L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL]

//>> GET_[L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL]

//>> GET_[L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL,
           L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK,
           L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK,
           L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK,
           L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK,
           L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK,
           L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK,
           L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK,
           L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK,
           L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK,
           L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK,
           L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK,
           L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK,
           L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline bool GET_L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline bool GET_L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE,
           L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE]

//>> SET_[L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE,
           L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE]

//>> GET_[L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE,
           L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE]

//>> SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> GET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> GET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline bool GET_L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> GET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> GET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline bool GET_L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline bool GET_L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> SET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> GET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline bool GET_L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> SET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> SET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> SET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> GET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> GET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline bool GET_L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> SET_[L2TRA_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_SPARE_LT]

//>> SET_[L2TRA_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_SPARE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_SPARE_LT]

//>> SET_[L2TRA_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_9_SPARE_LT]

//>> CLEAR_[L2TRA_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR0_CONFIG_9_SPARE_LT]

//>> GET_[L2TRA_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_9_SPARE_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_SPARE_LT]

//>> GET_[L2TRA_TR0_CONFIG_9_SPARE_LT]
static inline bool GET_L2TRA_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_9_SPARE_LT]

//>> PREP_[L2TRA_TR1_CONFIG_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR1_CONFIG_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR1_CONFIG_0]

//>> GET_[L2TRA_TR1_CONFIG_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR1_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_0;
#endif
    return fapi2::getScom(i_target, L2TRA_TR1_CONFIG_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_0]

//>> PUT_[L2TRA_TR1_CONFIG_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR1_CONFIG_0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_0));
#endif
    return fapi2::putScom(i_target, L2TRA_TR1_CONFIG_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR1_CONFIG_0]


//>> SET_[L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_0));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63]

//>> SET_[L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_0));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63]

//>> GET_[L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_0));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63]

//>> PREP_[L3_MISC_L3CERRS_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_FIR_ACTION0_REG]

//>> GET_[L3_MISC_L3CERRS_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_ACTION0_REG]

//>> PUT_[L3_MISC_L3CERRS_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_FIR_ACTION0_REG]


//>> SET_[L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0,
           L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0]

//>> SET_[L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0,
           L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0]

//>> GET_[L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_ACTION0_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0,
           L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0]

//>> PREP_[L3_MISC_L3CERRS_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_FIR_ACTION1_REG]

//>> GET_[L3_MISC_L3CERRS_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_ACTION1_REG]

//>> PUT_[L3_MISC_L3CERRS_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_FIR_ACTION1_REG]


//>> SET_[L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1,
           L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1]

//>> SET_[L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1,
           L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1]

//>> GET_[L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1,
           L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1]

//>> PREP_[L3_MISC_L3CERRS_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_FIR_MASK_REG_RW]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RW]

//>> PUT_[L3_MISC_L3CERRS_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_FIR_MASK_REG_RW]

//>> PREP_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND]

//>> PUT_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND]

//>> PREP_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR]

//>> PUT_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR]


//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]

//>> SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]

//>> CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]

//>> GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]
static inline bool GET_L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_FIR_MASK_REG_RW, L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND,
                           L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK]

//>> PREP_[L3_MISC_L3CERRS_PM_LCO_DIS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_PM_LCO_DIS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PM_LCO_DIS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_PM_LCO_DIS_REG]

//>> GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_PM_LCO_DIS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PM_LCO_DIS_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_PM_LCO_DIS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG]

//>> PUT_[L3_MISC_L3CERRS_PM_LCO_DIS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_PM_LCO_DIS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_PM_LCO_DIS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_PM_LCO_DIS_REG]


//>> SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]

//>> SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]

//>> SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]

//>> GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]

//>> GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]
static inline bool GET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG]

//>> SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]

//>> SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]

//>> SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]

//>> GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]

//>> GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]
static inline bool GET_L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_LCO_DIS_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG]

//>> PREP_[QME_CISR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_CISR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CISR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_CISR]

//>> GET_[QME_CISR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_CISR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CISR;
#endif
    return fapi2::getScom(i_target, QME_CISR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_CISR]

//>> PUT_[QME_CISR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_CISR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return fapi2::putScom(i_target, QME_CISR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_CISR]


//>> SET_[QME_CISR_HYP_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_HYP_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_HYP_INTR_PRESENT,
           QME_CISR_HYP_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_HYP_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_HYP_INTR_PRESENT]

//>> SET_[QME_CISR_HYP_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_HYP_INTR_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_HYP_INTR_PRESENT,
           QME_CISR_HYP_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_HYP_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_HYP_INTR_PRESENT]

//>> GET_[QME_CISR_HYP_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_HYP_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_HYP_INTR_PRESENT,
           QME_CISR_HYP_INTR_PRESENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_HYP_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_HYP_INTR_PRESENT]

//>> SET_[QME_CISR_OS_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_OS_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_OS_INTR_PRESENT,
           QME_CISR_OS_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_OS_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_OS_INTR_PRESENT]

//>> SET_[QME_CISR_OS_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_OS_INTR_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_OS_INTR_PRESENT,
           QME_CISR_OS_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_OS_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_OS_INTR_PRESENT]

//>> GET_[QME_CISR_OS_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_OS_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_OS_INTR_PRESENT,
           QME_CISR_OS_INTR_PRESENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_OS_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_OS_INTR_PRESENT]

//>> SET_[QME_CISR_MSGSND_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSND_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSND_INTR_PRESENT,
           QME_CISR_MSGSND_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_MSGSND_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSND_INTR_PRESENT]

//>> SET_[QME_CISR_MSGSND_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSND_INTR_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSND_INTR_PRESENT,
           QME_CISR_MSGSND_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_MSGSND_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSND_INTR_PRESENT]

//>> GET_[QME_CISR_MSGSND_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_MSGSND_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_MSGSND_INTR_PRESENT,
           QME_CISR_MSGSND_INTR_PRESENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_MSGSND_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MSGSND_INTR_PRESENT]

//>> SET_[QME_CISR_EBB_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_EBB_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_EBB_INTR_PRESENT,
           QME_CISR_EBB_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_EBB_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_EBB_INTR_PRESENT]

//>> SET_[QME_CISR_EBB_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_EBB_INTR_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_EBB_INTR_PRESENT,
           QME_CISR_EBB_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_EBB_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_EBB_INTR_PRESENT]

//>> GET_[QME_CISR_EBB_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_EBB_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_EBB_INTR_PRESENT,
           QME_CISR_EBB_INTR_PRESENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_EBB_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_EBB_INTR_PRESENT]

//>> SET_[QME_CISR_HYP_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_HYP_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_HYP_INTR_REQUESTED,
           QME_CISR_HYP_INTR_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_HYP_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_HYP_INTR_REQUESTED]

//>> SET_[QME_CISR_HYP_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_HYP_INTR_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_HYP_INTR_REQUESTED,
           QME_CISR_HYP_INTR_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_HYP_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_HYP_INTR_REQUESTED]

//>> GET_[QME_CISR_HYP_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_HYP_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_HYP_INTR_REQUESTED,
           QME_CISR_HYP_INTR_REQUESTED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_HYP_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_HYP_INTR_REQUESTED]

//>> SET_[QME_CISR_OS_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_OS_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_OS_INTR_REQUESTED,
           QME_CISR_OS_INTR_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_OS_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_OS_INTR_REQUESTED]

//>> SET_[QME_CISR_OS_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_OS_INTR_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_OS_INTR_REQUESTED,
           QME_CISR_OS_INTR_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_OS_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_OS_INTR_REQUESTED]

//>> GET_[QME_CISR_OS_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_OS_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_OS_INTR_REQUESTED,
           QME_CISR_OS_INTR_REQUESTED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_OS_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_OS_INTR_REQUESTED]

//>> SET_[QME_CISR_MSGSND_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSND_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSND_INTR_REQUESTED,
           QME_CISR_MSGSND_INTR_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_MSGSND_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSND_INTR_REQUESTED]

//>> SET_[QME_CISR_MSGSND_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSND_INTR_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSND_INTR_REQUESTED,
           QME_CISR_MSGSND_INTR_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_MSGSND_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSND_INTR_REQUESTED]

//>> GET_[QME_CISR_MSGSND_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_MSGSND_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_MSGSND_INTR_REQUESTED,
           QME_CISR_MSGSND_INTR_REQUESTED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_MSGSND_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MSGSND_INTR_REQUESTED]

//>> SET_[QME_CISR_MSGSND_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSND_INTR_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSND_INTR_SAMPLE,
           QME_CISR_MSGSND_INTR_SAMPLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_MSGSND_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSND_INTR_SAMPLE]

//>> SET_[QME_CISR_MSGSND_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSND_INTR_SAMPLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSND_INTR_SAMPLE,
           QME_CISR_MSGSND_INTR_SAMPLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_MSGSND_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSND_INTR_SAMPLE]

//>> GET_[QME_CISR_MSGSND_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_MSGSND_INTR_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_MSGSND_INTR_SAMPLE,
           QME_CISR_MSGSND_INTR_SAMPLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_MSGSND_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MSGSND_INTR_SAMPLE]

//>> SET_[QME_CISR_MSGSND_ACK]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSND_ACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSND_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_MSGSND_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSND_ACK]

//>> SET_[QME_CISR_MSGSND_ACK]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSND_ACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSND_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_MSGSND_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSND_ACK]

//>> SET_[QME_CISR_MSGSND_ACK]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSND_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_MSGSND_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_MSGSND_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSND_ACK]

//>> CLEAR_[QME_CISR_MSGSND_ACK]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_MSGSND_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_MSGSND_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_MSGSND_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_MSGSND_ACK]

//>> GET_[QME_CISR_MSGSND_ACK]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_MSGSND_ACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_MSGSND_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_MSGSND_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MSGSND_ACK]

//>> GET_[QME_CISR_MSGSND_ACK]
static inline bool GET_QME_CISR_MSGSND_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_MSGSND_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_MSGSND_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MSGSND_ACK]

//>> SET_[QME_CISR_MALF_ALERT_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MALF_ALERT_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MALF_ALERT_PRESENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_MALF_ALERT_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MALF_ALERT_PRESENT]

//>> SET_[QME_CISR_MALF_ALERT_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MALF_ALERT_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MALF_ALERT_PRESENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_MALF_ALERT_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MALF_ALERT_PRESENT]

//>> SET_[QME_CISR_MALF_ALERT_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MALF_ALERT_PRESENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_MALF_ALERT_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_MALF_ALERT_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MALF_ALERT_PRESENT]

//>> CLEAR_[QME_CISR_MALF_ALERT_PRESENT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_MALF_ALERT_PRESENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_MALF_ALERT_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_MALF_ALERT_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_MALF_ALERT_PRESENT]

//>> GET_[QME_CISR_MALF_ALERT_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_MALF_ALERT_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_MALF_ALERT_PRESENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_MALF_ALERT_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MALF_ALERT_PRESENT]

//>> GET_[QME_CISR_MALF_ALERT_PRESENT]
static inline bool GET_QME_CISR_MALF_ALERT_PRESENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_MALF_ALERT_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_MALF_ALERT_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MALF_ALERT_PRESENT]

//>> SET_[QME_CISR_MALF_ALERT_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MALF_ALERT_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MALF_ALERT_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_MALF_ALERT_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MALF_ALERT_REQUESTED]

//>> SET_[QME_CISR_MALF_ALERT_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MALF_ALERT_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MALF_ALERT_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_MALF_ALERT_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MALF_ALERT_REQUESTED]

//>> SET_[QME_CISR_MALF_ALERT_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MALF_ALERT_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_MALF_ALERT_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_MALF_ALERT_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MALF_ALERT_REQUESTED]

//>> CLEAR_[QME_CISR_MALF_ALERT_REQUESTED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_MALF_ALERT_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_MALF_ALERT_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_MALF_ALERT_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_MALF_ALERT_REQUESTED]

//>> GET_[QME_CISR_MALF_ALERT_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_MALF_ALERT_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_MALF_ALERT_REQUESTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_MALF_ALERT_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MALF_ALERT_REQUESTED]

//>> GET_[QME_CISR_MALF_ALERT_REQUESTED]
static inline bool GET_QME_CISR_MALF_ALERT_REQUESTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_MALF_ALERT_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_MALF_ALERT_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MALF_ALERT_REQUESTED]

//>> SET_[QME_CISR_MSGSNDU_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSNDU_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSNDU_INTR_PRESENT,
           QME_CISR_MSGSNDU_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_MSGSNDU_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSNDU_INTR_PRESENT]

//>> SET_[QME_CISR_MSGSNDU_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSNDU_INTR_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSNDU_INTR_PRESENT,
           QME_CISR_MSGSNDU_INTR_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_MSGSNDU_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSNDU_INTR_PRESENT]

//>> GET_[QME_CISR_MSGSNDU_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_MSGSNDU_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_MSGSNDU_INTR_PRESENT,
           QME_CISR_MSGSNDU_INTR_PRESENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_MSGSNDU_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MSGSNDU_INTR_PRESENT]

//>> SET_[QME_CISR_MSGSNDU_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSNDU_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSNDU_INTR_REQUESTED,
           QME_CISR_MSGSNDU_INTR_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_MSGSNDU_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSNDU_INTR_REQUESTED]

//>> SET_[QME_CISR_MSGSNDU_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSNDU_INTR_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSNDU_INTR_REQUESTED,
           QME_CISR_MSGSNDU_INTR_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_MSGSNDU_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSNDU_INTR_REQUESTED]

//>> GET_[QME_CISR_MSGSNDU_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_MSGSNDU_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_MSGSNDU_INTR_REQUESTED,
           QME_CISR_MSGSNDU_INTR_REQUESTED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_MSGSNDU_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MSGSNDU_INTR_REQUESTED]

//>> SET_[QME_CISR_MSGSNDU_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSNDU_INTR_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSNDU_INTR_SAMPLE,
           QME_CISR_MSGSNDU_INTR_SAMPLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_MSGSNDU_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSNDU_INTR_SAMPLE]

//>> SET_[QME_CISR_MSGSNDU_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_MSGSNDU_INTR_SAMPLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_MSGSNDU_INTR_SAMPLE,
           QME_CISR_MSGSNDU_INTR_SAMPLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_MSGSNDU_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_MSGSNDU_INTR_SAMPLE]

//>> GET_[QME_CISR_MSGSNDU_INTR_SAMPLE]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_MSGSNDU_INTR_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_MSGSNDU_INTR_SAMPLE,
           QME_CISR_MSGSNDU_INTR_SAMPLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_MSGSNDU_INTR_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_MSGSNDU_INTR_SAMPLE]

//>> SET_[QME_CISR_TFCS_DEC_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_DEC_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_TFCS_DEC_PRESENT,
           QME_CISR_TFCS_DEC_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_TFCS_DEC_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_DEC_PRESENT]

//>> SET_[QME_CISR_TFCS_DEC_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_DEC_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_TFCS_DEC_PRESENT,
           QME_CISR_TFCS_DEC_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_TFCS_DEC_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_DEC_PRESENT]

//>> GET_[QME_CISR_TFCS_DEC_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_TFCS_DEC_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_TFCS_DEC_PRESENT,
           QME_CISR_TFCS_DEC_PRESENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_TFCS_DEC_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_TFCS_DEC_PRESENT]

//>> SET_[QME_CISR_TFCS_DEC_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_DEC_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_TFCS_DEC_REQUESTED,
           QME_CISR_TFCS_DEC_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_TFCS_DEC_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_DEC_REQUESTED]

//>> SET_[QME_CISR_TFCS_DEC_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_DEC_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_TFCS_DEC_REQUESTED,
           QME_CISR_TFCS_DEC_REQUESTED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_TFCS_DEC_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_DEC_REQUESTED]

//>> GET_[QME_CISR_TFCS_DEC_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_TFCS_DEC_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_TFCS_DEC_REQUESTED,
           QME_CISR_TFCS_DEC_REQUESTED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_TFCS_DEC_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_TFCS_DEC_REQUESTED]

//>> SET_[QME_CISR_TFCS_HDEC_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_HDEC_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_TFCS_HDEC_PRESENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_TFCS_HDEC_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_HDEC_PRESENT]

//>> SET_[QME_CISR_TFCS_HDEC_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_HDEC_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_TFCS_HDEC_PRESENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_TFCS_HDEC_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_HDEC_PRESENT]

//>> SET_[QME_CISR_TFCS_HDEC_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_HDEC_PRESENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_TFCS_HDEC_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_TFCS_HDEC_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_HDEC_PRESENT]

//>> CLEAR_[QME_CISR_TFCS_HDEC_PRESENT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_TFCS_HDEC_PRESENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_TFCS_HDEC_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_TFCS_HDEC_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_TFCS_HDEC_PRESENT]

//>> GET_[QME_CISR_TFCS_HDEC_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_TFCS_HDEC_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_TFCS_HDEC_PRESENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_TFCS_HDEC_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_TFCS_HDEC_PRESENT]

//>> GET_[QME_CISR_TFCS_HDEC_PRESENT]
static inline bool GET_QME_CISR_TFCS_HDEC_PRESENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_TFCS_HDEC_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_TFCS_HDEC_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_TFCS_HDEC_PRESENT]

//>> SET_[QME_CISR_TFCS_HDEC_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_HDEC_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_TFCS_HDEC_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_TFCS_HDEC_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_HDEC_REQUESTED]

//>> SET_[QME_CISR_TFCS_HDEC_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_HDEC_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_TFCS_HDEC_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_TFCS_HDEC_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_HDEC_REQUESTED]

//>> SET_[QME_CISR_TFCS_HDEC_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_TFCS_HDEC_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_TFCS_HDEC_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_TFCS_HDEC_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_TFCS_HDEC_REQUESTED]

//>> CLEAR_[QME_CISR_TFCS_HDEC_REQUESTED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_TFCS_HDEC_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_TFCS_HDEC_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_TFCS_HDEC_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_TFCS_HDEC_REQUESTED]

//>> GET_[QME_CISR_TFCS_HDEC_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_TFCS_HDEC_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_TFCS_HDEC_REQUESTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_TFCS_HDEC_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_TFCS_HDEC_REQUESTED]

//>> GET_[QME_CISR_TFCS_HDEC_REQUESTED]
static inline bool GET_QME_CISR_TFCS_HDEC_REQUESTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_TFCS_HDEC_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_TFCS_HDEC_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_TFCS_HDEC_REQUESTED]

//>> SET_[QME_CISR_DPDES_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_DPDES_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_DPDES_INTR_PRESENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_DPDES_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_DPDES_INTR_PRESENT]

//>> SET_[QME_CISR_DPDES_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_DPDES_INTR_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_DPDES_INTR_PRESENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_DPDES_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_DPDES_INTR_PRESENT]

//>> SET_[QME_CISR_DPDES_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_DPDES_INTR_PRESENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_DPDES_INTR_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_DPDES_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_DPDES_INTR_PRESENT]

//>> CLEAR_[QME_CISR_DPDES_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_DPDES_INTR_PRESENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_DPDES_INTR_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_DPDES_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_DPDES_INTR_PRESENT]

//>> GET_[QME_CISR_DPDES_INTR_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_DPDES_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_DPDES_INTR_PRESENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_DPDES_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_DPDES_INTR_PRESENT]

//>> GET_[QME_CISR_DPDES_INTR_PRESENT]
static inline bool GET_QME_CISR_DPDES_INTR_PRESENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_DPDES_INTR_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_DPDES_INTR_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_DPDES_INTR_PRESENT]

//>> SET_[QME_CISR_DPDES_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_DPDES_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_DPDES_INTR_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_DPDES_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_DPDES_INTR_REQUESTED]

//>> SET_[QME_CISR_DPDES_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_DPDES_INTR_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_DPDES_INTR_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_DPDES_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_DPDES_INTR_REQUESTED]

//>> SET_[QME_CISR_DPDES_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_DPDES_INTR_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_DPDES_INTR_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_DPDES_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_DPDES_INTR_REQUESTED]

//>> CLEAR_[QME_CISR_DPDES_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_DPDES_INTR_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_DPDES_INTR_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_DPDES_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_DPDES_INTR_REQUESTED]

//>> GET_[QME_CISR_DPDES_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_DPDES_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_DPDES_INTR_REQUESTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_DPDES_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_DPDES_INTR_REQUESTED]

//>> GET_[QME_CISR_DPDES_INTR_REQUESTED]
static inline bool GET_QME_CISR_DPDES_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_DPDES_INTR_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_DPDES_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_DPDES_INTR_REQUESTED]

//>> SET_[QME_CISR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_PC_INTR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_PC_INTR_PENDING]

//>> SET_[QME_CISR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_PC_INTR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_PC_INTR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_PC_INTR_PENDING]

//>> SET_[QME_CISR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_PC_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_PC_INTR_PENDING]

//>> CLEAR_[QME_CISR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_PC_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_PC_INTR_PENDING]

//>> GET_[QME_CISR_PC_INTR_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_PC_INTR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_PC_INTR_PENDING]

//>> GET_[QME_CISR_PC_INTR_PENDING]
static inline bool GET_QME_CISR_PC_INTR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_PC_INTR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_PC_INTR_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_PC_INTR_PENDING]

//>> SET_[QME_CISR_PC_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_PC_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_PC_INTR_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_PC_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_PC_INTR_REQUESTED]

//>> SET_[QME_CISR_PC_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_PC_INTR_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_PC_INTR_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_PC_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_PC_INTR_REQUESTED]

//>> SET_[QME_CISR_PC_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_PC_INTR_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_PC_INTR_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_PC_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_PC_INTR_REQUESTED]

//>> CLEAR_[QME_CISR_PC_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_PC_INTR_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_PC_INTR_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_PC_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_PC_INTR_REQUESTED]

//>> GET_[QME_CISR_PC_INTR_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_PC_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_PC_INTR_REQUESTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_PC_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_PC_INTR_REQUESTED]

//>> GET_[QME_CISR_PC_INTR_REQUESTED]
static inline bool GET_QME_CISR_PC_INTR_REQUESTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_PC_INTR_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_PC_INTR_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_PC_INTR_REQUESTED]

//>> SET_[QME_CISR_REG_WKUP_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_REG_WKUP_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_REG_WKUP_PRESENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_REG_WKUP_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_REG_WKUP_PRESENT]

//>> SET_[QME_CISR_REG_WKUP_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_REG_WKUP_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_REG_WKUP_PRESENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_REG_WKUP_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_REG_WKUP_PRESENT]

//>> SET_[QME_CISR_REG_WKUP_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_REG_WKUP_PRESENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_REG_WKUP_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_REG_WKUP_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_REG_WKUP_PRESENT]

//>> CLEAR_[QME_CISR_REG_WKUP_PRESENT]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_REG_WKUP_PRESENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_REG_WKUP_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_REG_WKUP_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_REG_WKUP_PRESENT]

//>> GET_[QME_CISR_REG_WKUP_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_REG_WKUP_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_REG_WKUP_PRESENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_REG_WKUP_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_REG_WKUP_PRESENT]

//>> GET_[QME_CISR_REG_WKUP_PRESENT]
static inline bool GET_QME_CISR_REG_WKUP_PRESENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_REG_WKUP_PRESENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_REG_WKUP_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_REG_WKUP_PRESENT]

//>> SET_[QME_CISR_REG_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_REG_WKUP_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_REG_WKUP_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CISR_REG_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_REG_WKUP_REQUESTED]

//>> SET_[QME_CISR_REG_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_REG_WKUP_REQUESTED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.insertFromRight<QME_CISR_REG_WKUP_REQUESTED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CISR_REG_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_REG_WKUP_REQUESTED]

//>> SET_[QME_CISR_REG_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& SET_QME_CISR_REG_WKUP_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.setBit<QME_CISR_REG_WKUP_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_CISR_REG_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CISR_REG_WKUP_REQUESTED]

//>> CLEAR_[QME_CISR_REG_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_CISR_REG_WKUP_REQUESTED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return o_data.clearBit<QME_CISR_REG_WKUP_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_CISR_REG_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_CISR_REG_WKUP_REQUESTED]

//>> GET_[QME_CISR_REG_WKUP_REQUESTED]
static inline fapi2::buffer<uint64_t>& GET_QME_CISR_REG_WKUP_REQUESTED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.extractToRight<QME_CISR_REG_WKUP_REQUESTED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CISR_REG_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_REG_WKUP_REQUESTED]

//>> GET_[QME_CISR_REG_WKUP_REQUESTED]
static inline bool GET_QME_CISR_REG_WKUP_REQUESTED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CISR));
#endif
    return i_data.getBit<QME_CISR_REG_WKUP_REQUESTED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_CISR_REG_WKUP_REQUESTED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CISR_REG_WKUP_REQUESTED]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
