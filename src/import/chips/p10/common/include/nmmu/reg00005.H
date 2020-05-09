/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00005.H $         */
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

#ifndef __NMMU_REG00005_H_
#define __NMMU_REG00005_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


//>> PREP_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG]

//>> PUT_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG]


//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL0_REG_TOP_ID_XLAT_TBL0]

//>> PREP_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG]

//>> PUT_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG]


//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL1_REG_TOP_ID_XLAT_TBL1]

//>> PREP_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG]

//>> PUT_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG]


//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL2_REG_TOP_ID_XLAT_TBL2]

//>> PREP_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG]

//>> PUT_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG]


//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3,
           FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_TOP_ID_XLAT_TBL3_REG_TOP_ID_XLAT_TBL3]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
