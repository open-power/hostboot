/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00004.H $         */
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

#ifndef __OMIC_REG00004_H_
#define __OMIC_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[CTL_REGS_TX_CNTL1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_TX_CNTL1_PG]

//>> GET_[CTL_REGS_TX_CNTL1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL1_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL1_PG]

//>> PUT_[CTL_REGS_TX_CNTL1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL1_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_TX_CNTL1_PG]


//>> SET_[CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL,
           CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL]

//>> SET_[CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL,
           CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL]

//>> GET_[CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL,
           CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
