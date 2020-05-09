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


//>> PREP_[CTL_REGS_RX_MODE13_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE13_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE13_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_MODE13_PG]

//>> GET_[CTL_REGS_RX_MODE13_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE13_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE13_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE13_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_MODE13_PG]

//>> PUT_[CTL_REGS_RX_MODE13_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE13_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE13_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_MODE13_PG]


//>> SET_[CTL_REGS_RX_MODE13_PG_1_FILTER_ENA]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE13_PG_1_FILTER_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE13_PG_1_FILTER_ENA,
           CTL_REGS_RX_MODE13_PG_1_FILTER_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_1_FILTER_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE13_PG_1_FILTER_ENA]

//>> SET_[CTL_REGS_RX_MODE13_PG_1_FILTER_ENA]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE13_PG_1_FILTER_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE13_PG_1_FILTER_ENA,
           CTL_REGS_RX_MODE13_PG_1_FILTER_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_1_FILTER_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE13_PG_1_FILTER_ENA]

//>> GET_[CTL_REGS_RX_MODE13_PG_1_FILTER_ENA]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE13_PG_1_FILTER_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE13_PG_1_FILTER_ENA,
           CTL_REGS_RX_MODE13_PG_1_FILTER_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_1_FILTER_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE13_PG_1_FILTER_ENA]

//>> SET_[CTL_REGS_RX_MODE13_PG_1_FILTER_PAT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE13_PG_1_FILTER_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE13_PG_1_FILTER_PAT,
           CTL_REGS_RX_MODE13_PG_1_FILTER_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_1_FILTER_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE13_PG_1_FILTER_PAT]

//>> SET_[CTL_REGS_RX_MODE13_PG_1_FILTER_PAT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE13_PG_1_FILTER_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE13_PG_1_FILTER_PAT,
           CTL_REGS_RX_MODE13_PG_1_FILTER_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_1_FILTER_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE13_PG_1_FILTER_PAT]

//>> GET_[CTL_REGS_RX_MODE13_PG_1_FILTER_PAT]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE13_PG_1_FILTER_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE13_PG_1_FILTER_PAT,
           CTL_REGS_RX_MODE13_PG_1_FILTER_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_1_FILTER_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE13_PG_1_FILTER_PAT]

//>> SET_[CTL_REGS_RX_MODE13_PG_2_FILTER_ENA]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE13_PG_2_FILTER_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE13_PG_2_FILTER_ENA,
           CTL_REGS_RX_MODE13_PG_2_FILTER_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_2_FILTER_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE13_PG_2_FILTER_ENA]

//>> SET_[CTL_REGS_RX_MODE13_PG_2_FILTER_ENA]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE13_PG_2_FILTER_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE13_PG_2_FILTER_ENA,
           CTL_REGS_RX_MODE13_PG_2_FILTER_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_2_FILTER_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE13_PG_2_FILTER_ENA]

//>> GET_[CTL_REGS_RX_MODE13_PG_2_FILTER_ENA]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE13_PG_2_FILTER_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE13_PG_2_FILTER_ENA,
           CTL_REGS_RX_MODE13_PG_2_FILTER_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_2_FILTER_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE13_PG_2_FILTER_ENA]

//>> SET_[CTL_REGS_RX_MODE13_PG_2_FILTER_PAT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE13_PG_2_FILTER_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE13_PG_2_FILTER_PAT,
           CTL_REGS_RX_MODE13_PG_2_FILTER_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_2_FILTER_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE13_PG_2_FILTER_PAT]

//>> SET_[CTL_REGS_RX_MODE13_PG_2_FILTER_PAT]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE13_PG_2_FILTER_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE13_PG_2_FILTER_PAT,
           CTL_REGS_RX_MODE13_PG_2_FILTER_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_2_FILTER_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE13_PG_2_FILTER_PAT]

//>> GET_[CTL_REGS_RX_MODE13_PG_2_FILTER_PAT]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE13_PG_2_FILTER_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE13_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE13_PG_2_FILTER_PAT,
           CTL_REGS_RX_MODE13_PG_2_FILTER_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE13_PG_2_FILTER_PAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE13_PG_2_FILTER_PAT]

//>> PREP_[CTL_REGS_RX_MODE23_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE23_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE23_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_MODE23_PG]

//>> GET_[CTL_REGS_RX_MODE23_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE23_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE23_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE23_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG]

//>> PUT_[CTL_REGS_RX_MODE23_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE23_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE23_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_MODE23_PG]


//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL,
           CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL]

//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL,
           CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL]

//>> GET_[CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL,
           CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_PEAK1_H_SEL]

//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL,
           CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL]

//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL,
           CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL]

//>> GET_[CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL,
           CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_PEAK2_H_SEL]

//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]

//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]

//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]

//>> CLEAR_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]

//>> GET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]

//>> GET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]
static inline bool GET_CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_PEAK1_INVALID_LOCK_EN]

//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]

//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]

//>> SET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]

//>> CLEAR_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]

//>> GET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]

//>> GET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]
static inline bool GET_CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_PEAK2_INVALID_LOCK_EN]

//>> SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]

//>> SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]

//>> SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]

//>> CLEAR_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]

//>> GET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]

//>> GET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]
static inline bool GET_CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_CONVERGE_UP_ENABLE]

//>> SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]

//>> SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]

//>> SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]

//>> CLEAR_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]

//>> GET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]

//>> GET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]
static inline bool GET_CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE23_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE23_PG_CONVERGE_DOWN_ENABLE]

//>> PREP_[CTL_REGS_RX_MODE6_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE6_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_MODE6_PG]

//>> GET_[CTL_REGS_RX_MODE6_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE6_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_MODE6_PG]

//>> PUT_[CTL_REGS_RX_MODE6_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE6_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_MODE6_PG]


//>> SET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2,
           CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2]

//>> SET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2,
           CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2]

//>> GET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2,
           CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2]

//>> SET_[CTL_REGS_RX_MODE6_PG_THRESH3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE6_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE6_PG_THRESH3,
           CTL_REGS_RX_MODE6_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE6_PG_THRESH3]

//>> SET_[CTL_REGS_RX_MODE6_PG_THRESH3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE6_PG_THRESH3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE6_PG_THRESH3,
           CTL_REGS_RX_MODE6_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE6_PG_THRESH3]

//>> GET_[CTL_REGS_RX_MODE6_PG_THRESH3]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE6_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE6_PG_THRESH3,
           CTL_REGS_RX_MODE6_PG_THRESH3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE6_PG_THRESH3]

//>> SET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3,
           CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3]

//>> SET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3,
           CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3]

//>> GET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3,
           CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3]

//>> SET_[CTL_REGS_RX_MODE6_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE6_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE6_PG_THRESH4,
           CTL_REGS_RX_MODE6_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE6_PG_THRESH4]

//>> SET_[CTL_REGS_RX_MODE6_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE6_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE6_PG_THRESH4,
           CTL_REGS_RX_MODE6_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE6_PG_THRESH4]

//>> GET_[CTL_REGS_RX_MODE6_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE6_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE6_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE6_PG_THRESH4,
           CTL_REGS_RX_MODE6_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE6_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE6_PG_THRESH4]

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

//>> PREP_[DATASM_REGS_RX_CNT11_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT11_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT11_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNT11_PG]

//>> GET_[DATASM_REGS_RX_CNT11_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT11_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT11_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT11_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT11_PG]

//>> PUT_[DATASM_REGS_RX_CNT11_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT11_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT11_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT11_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNT11_PG]


//>> SET_[DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT11_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15,
           DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15]

//>> SET_[DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT11_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15,
           DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15]

//>> GET_[DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT11_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15,
           DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15]

//>> PREP_[DATASM_REGS_RX_CNT21_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT21_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT21_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNT21_PG]

//>> GET_[DATASM_REGS_RX_CNT21_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT21_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT21_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT21_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT21_PG]

//>> PUT_[DATASM_REGS_RX_CNT21_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT21_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT21_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT21_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNT21_PG]


//>> SET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT21_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]

//>> SET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT21_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]

//>> SET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT21_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]

//>> CLEAR_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT21_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]

//>> GET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT21_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]

//>> GET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]
static inline bool GET_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT21_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET]

//>> PREP_[DATASM_REGS_RX_CNTL2_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL2_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNTL2_PG]

//>> GET_[DATASM_REGS_RX_CNTL2_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL2_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL2_PG]

//>> PUT_[DATASM_REGS_RX_CNTL2_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL2_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNTL2_PG]


//>> SET_[DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL,
           DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL]

//>> SET_[DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL2_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL,
           DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL]

//>> GET_[DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL2_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL,
           DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL2_PG_RX_SERVO_OP_QUEUE0_WO_PULSE_SLOW_SIGNAL]

//>> PREP_[DATASM_REGS_RX_STAT2_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT2_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT2_PG]

//>> GET_[DATASM_REGS_RX_STAT2_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT2_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT2_PG]

//>> PUT_[DATASM_REGS_RX_STAT2_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT2_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT2_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT2_PG]


//>> SET_[DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT2_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL,
           DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT2_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL,
           DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT2_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL,
           DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT2_PG_DIR_CHG_CNT_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT2_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL,
           DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT2_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL,
           DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT2_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL,
           DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT2_PG_VOTE_DIFF_RO_SIGNAL]

//>> PREP_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL10_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL10_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG]

//>> GET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL10_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL10_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG]

//>> PUT_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL10_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL10_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL10_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG]


//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL10_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2,
           TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2]

//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL10_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2,
           TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2]

//>> GET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL10_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2,
           TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2]

//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL10_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3,
           TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3]

//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL10_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3,
           TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3]

//>> GET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL10_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3,
           TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
