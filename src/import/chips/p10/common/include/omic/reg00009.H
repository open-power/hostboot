/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00009.H $         */
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

#ifndef __OMIC_REG00009_H_
#define __OMIC_REG00009_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[PMU_CNTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PMU_CNTR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PMU_CNTR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PMU_CNTR]

//>> GET_[PMU_CNTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PMU_CNTR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PMU_CNTR;
#endif
    return fapi2::getScom(i_target, PMU_CNTR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PMU_CNTR]

//>> PUT_[PMU_CNTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PMU_CNTR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return fapi2::putScom(i_target, PMU_CNTR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PMU_CNTR]


//>> SET_[PMU_CNTR_3]
static inline fapi2::buffer<uint64_t>& SET_PMU_CNTR_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return o_data.insertFromRight<PMU_CNTR_3,
           PMU_CNTR_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access PMU_CNTR_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PMU_CNTR_3]

//>> SET_[PMU_CNTR_3]
static inline fapi2::buffer<uint64_t>& SET_PMU_CNTR_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return o_data.insertFromRight<PMU_CNTR_3,
           PMU_CNTR_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access PMU_CNTR_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PMU_CNTR_3]

//>> GET_[PMU_CNTR_3]
static inline fapi2::buffer<uint64_t>& GET_PMU_CNTR_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return i_data.extractToRight<PMU_CNTR_3,
           PMU_CNTR_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access PMU_CNTR_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PMU_CNTR_3]

//>> SET_[PMU_CNTR_2]
static inline fapi2::buffer<uint64_t>& SET_PMU_CNTR_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return o_data.insertFromRight<PMU_CNTR_2,
           PMU_CNTR_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access PMU_CNTR_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PMU_CNTR_2]

//>> SET_[PMU_CNTR_2]
static inline fapi2::buffer<uint64_t>& SET_PMU_CNTR_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return o_data.insertFromRight<PMU_CNTR_2,
           PMU_CNTR_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access PMU_CNTR_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PMU_CNTR_2]

//>> GET_[PMU_CNTR_2]
static inline fapi2::buffer<uint64_t>& GET_PMU_CNTR_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return i_data.extractToRight<PMU_CNTR_2,
           PMU_CNTR_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access PMU_CNTR_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PMU_CNTR_2]

//>> SET_[PMU_CNTR_1]
static inline fapi2::buffer<uint64_t>& SET_PMU_CNTR_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return o_data.insertFromRight<PMU_CNTR_1,
           PMU_CNTR_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access PMU_CNTR_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PMU_CNTR_1]

//>> SET_[PMU_CNTR_1]
static inline fapi2::buffer<uint64_t>& SET_PMU_CNTR_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return o_data.insertFromRight<PMU_CNTR_1,
           PMU_CNTR_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access PMU_CNTR_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PMU_CNTR_1]

//>> GET_[PMU_CNTR_1]
static inline fapi2::buffer<uint64_t>& GET_PMU_CNTR_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return i_data.extractToRight<PMU_CNTR_1,
           PMU_CNTR_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access PMU_CNTR_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PMU_CNTR_1]

//>> SET_[PMU_CNTR_0]
static inline fapi2::buffer<uint64_t>& SET_PMU_CNTR_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return o_data.insertFromRight<PMU_CNTR_0,
           PMU_CNTR_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access PMU_CNTR_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PMU_CNTR_0]

//>> SET_[PMU_CNTR_0]
static inline fapi2::buffer<uint64_t>& SET_PMU_CNTR_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return o_data.insertFromRight<PMU_CNTR_0,
           PMU_CNTR_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access PMU_CNTR_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PMU_CNTR_0]

//>> GET_[PMU_CNTR_0]
static inline fapi2::buffer<uint64_t>& GET_PMU_CNTR_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PMU_CNTR));
#endif
    return i_data.extractToRight<PMU_CNTR_0,
           PMU_CNTR_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access PMU_CNTR_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PMU_CNTR_0]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
