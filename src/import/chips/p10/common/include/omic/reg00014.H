/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00014.H $         */
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

#ifndef __OMIC_REG00014_H_
#define __OMIC_REG00014_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[CTL_REGS_TX_CNTL8_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL8_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_TX_CNTL8_PG]

//>> GET_[CTL_REGS_TX_CNTL8_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL8_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL8_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL8_PG]

//>> PUT_[CTL_REGS_TX_CNTL8_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL8_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL8_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_TX_CNTL8_PG]


//>> SET_[CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL8_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31,
           CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31]

//>> SET_[CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL8_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31,
           CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31]

//>> GET_[CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL8_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31,
           CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31]

//>> PREP_[DATASM_REGS_RX_CNT18_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT18_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT18_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNT18_PG]

//>> GET_[DATASM_REGS_RX_CNT18_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT18_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT18_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT18_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT18_PG]

//>> PUT_[DATASM_REGS_RX_CNT18_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT18_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT18_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT18_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNT18_PG]


//>> SET_[DATASM_REGS_RX_CNT18_PG_4]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT18_PG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT18_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT18_PG_4,
           DATASM_REGS_RX_CNT18_PG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT18_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT18_PG_4]

//>> SET_[DATASM_REGS_RX_CNT18_PG_4]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT18_PG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT18_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT18_PG_4,
           DATASM_REGS_RX_CNT18_PG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT18_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT18_PG_4]

//>> GET_[DATASM_REGS_RX_CNT18_PG_4]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT18_PG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT18_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT18_PG_4,
           DATASM_REGS_RX_CNT18_PG_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT18_PG_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT18_PG_4]

//>> SET_[DATASM_REGS_RX_CNT18_PG_5]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT18_PG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT18_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT18_PG_5,
           DATASM_REGS_RX_CNT18_PG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT18_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT18_PG_5]

//>> SET_[DATASM_REGS_RX_CNT18_PG_5]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT18_PG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT18_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT18_PG_5,
           DATASM_REGS_RX_CNT18_PG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT18_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT18_PG_5]

//>> GET_[DATASM_REGS_RX_CNT18_PG_5]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT18_PG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT18_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT18_PG_5,
           DATASM_REGS_RX_CNT18_PG_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT18_PG_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT18_PG_5]

//>> PREP_[DATASM_REGS_RX_CNT28_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT28_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT28_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNT28_PG]

//>> GET_[DATASM_REGS_RX_CNT28_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT28_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT28_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT28_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT28_PG]

//>> PUT_[DATASM_REGS_RX_CNT28_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT28_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT28_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT28_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNT28_PG]


//>> SET_[DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT28_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23,
           DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23]

//>> SET_[DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT28_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23,
           DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23]

//>> GET_[DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT28_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23,
           DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23]

//>> PREP_[DATASM_REGS_RX_STAT15_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT15_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT15_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT15_PG]

//>> GET_[DATASM_REGS_RX_STAT15_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT15_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT15_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT15_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT15_PG]

//>> PUT_[DATASM_REGS_RX_STAT15_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT15_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT15_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT15_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT15_PG]


//>> SET_[DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT15_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL,
           DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT15_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL,
           DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT15_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL,
           DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL]

//>> PREP_[DATASM_REGS_RX_STAT25_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT25_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT25_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT25_PG]

//>> GET_[DATASM_REGS_RX_STAT25_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT25_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT25_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT25_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT25_PG]

//>> PUT_[DATASM_REGS_RX_STAT25_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT25_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT25_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT25_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT25_PG]


//>> SET_[DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT25_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL,
           DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT25_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL,
           DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT25_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL,
           DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL]

//>> PREP_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL9_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL9_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG]

//>> GET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL9_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL9_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG]

//>> PUT_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL9_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL9_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL9_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG]


//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL9_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0,
           TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0]

//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL9_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0,
           TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0]

//>> GET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL9_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0,
           TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0]

//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL9_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1,
           TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1]

//>> SET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL9_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1,
           TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1]

//>> GET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL9_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1,
           TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1]

//>> PREP_[TX_CTL_SM_REGS_FIR_MASK_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_FIR_MASK_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_FIR_MASK_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TX_CTL_SM_REGS_FIR_MASK_PG]

//>> GET_[TX_CTL_SM_REGS_FIR_MASK_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_FIR_MASK_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_FIR_MASK_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_FIR_MASK_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_MASK_PG]

//>> PUT_[TX_CTL_SM_REGS_FIR_MASK_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_FIR_MASK_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_MASK_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_FIR_MASK_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TX_CTL_SM_REGS_FIR_MASK_PG]


//>> SET_[TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_MASK_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK,
           TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK]

//>> SET_[TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_MASK_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK,
           TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK]

//>> GET_[TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_MASK_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK,
           TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
