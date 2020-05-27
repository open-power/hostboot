/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00007.H $         */
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

#ifndef __OMIC_REG00007_H_
#define __OMIC_REG00007_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[MC_OMI_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MC_OMI_FIR_ACTION0_REG]

//>> GET_[MC_OMI_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MC_OMI_FIR_ACTION0_REG]

//>> PUT_[MC_OMI_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MC_OMI_FIR_ACTION0_REG]


//>> SET_[MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0,
           MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0]

//>> SET_[MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0,
           MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0]

//>> GET_[MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_ACTION0_REG));
#endif
    return i_data.extractToRight<MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0,
           MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0]

//>> PREP_[MC_OMI_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[MC_OMI_FIR_ACTION1_REG]

//>> GET_[MC_OMI_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[MC_OMI_FIR_ACTION1_REG]

//>> PUT_[MC_OMI_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[MC_OMI_FIR_ACTION1_REG]


//>> SET_[MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1,
           MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1]

//>> SET_[MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1,
           MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1]

//>> GET_[MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1,
           MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
