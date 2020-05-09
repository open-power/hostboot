/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00003.H $         */
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

#ifndef __NMMU_REG00003_H_
#define __NMMU_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


//>> PREP_[NMMU_PMU0_CNT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NMMU_PMU0_CNT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_PMU0_CNT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NMMU_PMU0_CNT_REG]

//>> GET_[NMMU_PMU0_CNT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NMMU_PMU0_CNT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NMMU_PMU0_CNT_REG;
#endif
    return fapi2::getScom(i_target, NMMU_PMU0_CNT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NMMU_PMU0_CNT_REG]

//>> PUT_[NMMU_PMU0_CNT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NMMU_PMU0_CNT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NMMU_PMU0_CNT_REG));
#endif
    return fapi2::putScom(i_target, NMMU_PMU0_CNT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NMMU_PMU0_CNT_REG]


//>> SET_[NMMU_PMU0_CNT_REG_MM_PMU0_CNT]
static inline fapi2::buffer<uint64_t>& SET_NMMU_PMU0_CNT_REG_MM_PMU0_CNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU0_CNT_REG));
#endif
    return o_data.insertFromRight<NMMU_PMU0_CNT_REG_MM_PMU0_CNT,
           NMMU_PMU0_CNT_REG_MM_PMU0_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access NMMU_PMU0_CNT_REG_MM_PMU0_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_PMU0_CNT_REG_MM_PMU0_CNT]

//>> SET_[NMMU_PMU0_CNT_REG_MM_PMU0_CNT]
static inline fapi2::buffer<uint64_t>& SET_NMMU_PMU0_CNT_REG_MM_PMU0_CNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU0_CNT_REG));
#endif
    return o_data.insertFromRight<NMMU_PMU0_CNT_REG_MM_PMU0_CNT,
           NMMU_PMU0_CNT_REG_MM_PMU0_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access NMMU_PMU0_CNT_REG_MM_PMU0_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NMMU_PMU0_CNT_REG_MM_PMU0_CNT]

//>> GET_[NMMU_PMU0_CNT_REG_MM_PMU0_CNT]
static inline fapi2::buffer<uint64_t>& GET_NMMU_PMU0_CNT_REG_MM_PMU0_CNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NMMU_PMU0_CNT_REG));
#endif
    return i_data.extractToRight<NMMU_PMU0_CNT_REG_MM_PMU0_CNT,
           NMMU_PMU0_CNT_REG_MM_PMU0_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access NMMU_PMU0_CNT_REG_MM_PMU0_CNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NMMU_PMU0_CNT_REG_MM_PMU0_CNT]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
