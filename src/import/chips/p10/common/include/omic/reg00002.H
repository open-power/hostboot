/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00002.H $         */
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

#ifndef __OMIC_REG00002_H_
#define __OMIC_REG00002_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[CTL_REGS_RX_MODE9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE9_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE9_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_MODE9_PG]

//>> GET_[CTL_REGS_RX_MODE9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE9_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE9_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE9_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_MODE9_PG]

//>> PUT_[CTL_REGS_RX_MODE9_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE9_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE9_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_MODE9_PG]


//>> SET_[CTL_REGS_RX_MODE9_PG_INC2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE9_PG_INC2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE9_PG_INC2,
           CTL_REGS_RX_MODE9_PG_INC2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_INC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE9_PG_INC2]

//>> SET_[CTL_REGS_RX_MODE9_PG_INC2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE9_PG_INC2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE9_PG_INC2,
           CTL_REGS_RX_MODE9_PG_INC2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_INC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE9_PG_INC2]

//>> GET_[CTL_REGS_RX_MODE9_PG_INC2]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE9_PG_INC2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE9_PG_INC2,
           CTL_REGS_RX_MODE9_PG_INC2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_INC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE9_PG_INC2]

//>> SET_[CTL_REGS_RX_MODE9_PG_DEC2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE9_PG_DEC2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE9_PG_DEC2,
           CTL_REGS_RX_MODE9_PG_DEC2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_DEC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE9_PG_DEC2]

//>> SET_[CTL_REGS_RX_MODE9_PG_DEC2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE9_PG_DEC2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE9_PG_DEC2,
           CTL_REGS_RX_MODE9_PG_DEC2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_DEC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE9_PG_DEC2]

//>> GET_[CTL_REGS_RX_MODE9_PG_DEC2]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE9_PG_DEC2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE9_PG_DEC2,
           CTL_REGS_RX_MODE9_PG_DEC2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_DEC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE9_PG_DEC2]

//>> SET_[CTL_REGS_RX_MODE9_PG_INC3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE9_PG_INC3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE9_PG_INC3,
           CTL_REGS_RX_MODE9_PG_INC3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_INC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE9_PG_INC3]

//>> SET_[CTL_REGS_RX_MODE9_PG_INC3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE9_PG_INC3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE9_PG_INC3,
           CTL_REGS_RX_MODE9_PG_INC3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_INC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE9_PG_INC3]

//>> GET_[CTL_REGS_RX_MODE9_PG_INC3]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE9_PG_INC3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE9_PG_INC3,
           CTL_REGS_RX_MODE9_PG_INC3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_INC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE9_PG_INC3]

//>> SET_[CTL_REGS_RX_MODE9_PG_DEC3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE9_PG_DEC3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE9_PG_DEC3,
           CTL_REGS_RX_MODE9_PG_DEC3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_DEC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE9_PG_DEC3]

//>> SET_[CTL_REGS_RX_MODE9_PG_DEC3]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE9_PG_DEC3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE9_PG_DEC3,
           CTL_REGS_RX_MODE9_PG_DEC3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_DEC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE9_PG_DEC3]

//>> GET_[CTL_REGS_RX_MODE9_PG_DEC3]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE9_PG_DEC3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE9_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE9_PG_DEC3,
           CTL_REGS_RX_MODE9_PG_DEC3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE9_PG_DEC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE9_PG_DEC3]

//>> PREP_[DATASM_REGS_RX_STAT13_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT13_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT13_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT13_PG]

//>> GET_[DATASM_REGS_RX_STAT13_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT13_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT13_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT13_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT13_PG]

//>> PUT_[DATASM_REGS_RX_STAT13_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT13_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT13_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT13_PG]


//>> SET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]

//>> CLEAR_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]
static inline bool GET_DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT13_PG_ANY_INIT_REQ_OR_RESET_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]

//>> CLEAR_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]
static inline bool GET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_CLOCK_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]

//>> CLEAR_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]
static inline bool GET_DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT13_PG_IREF_PARITYCHK_DATA_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]

//>> CLEAR_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]
static inline bool GET_DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT13_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT13_PG_PRVCPT_CHANGE_DET_RO_SIGNAL]

//>> PREP_[DATASM_REGS_RX_STAT23_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT23_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT23_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_STAT23_PG]

//>> GET_[DATASM_REGS_RX_STAT23_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT23_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT23_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT23_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT23_PG]

//>> PUT_[DATASM_REGS_RX_STAT23_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT23_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT23_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT23_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_STAT23_PG]


//>> SET_[DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT23_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL,
           DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL]

//>> SET_[DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT23_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL,
           DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL]

//>> GET_[DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT23_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL,
           DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_STAT23_PG_RX_DATA_PIPE_ALT_0_7_RO_SIGNAL]

//>> PREP_[TX_CTL_SM_REGS_FIR_RESET_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_FIR_RESET_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_FIR_RESET_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TX_CTL_SM_REGS_FIR_RESET_PG]

//>> GET_[TX_CTL_SM_REGS_FIR_RESET_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_FIR_RESET_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_FIR_RESET_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_FIR_RESET_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_RESET_PG]

//>> PUT_[TX_CTL_SM_REGS_FIR_RESET_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_FIR_RESET_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_FIR_RESET_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TX_CTL_SM_REGS_FIR_RESET_PG]


//>> SET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]

//>> SET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]

//>> SET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.setBit<TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]

//>> CLEAR_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.clearBit<TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]

//>> GET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]

//>> GET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]
static inline bool GET_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.getBit<TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS]

//>> SET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]

//>> SET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]

//>> SET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]
static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.setBit<TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]

//>> CLEAR_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return o_data.clearBit<TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]

//>> GET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]
static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]

//>> GET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]
static inline bool GET_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_FIR_RESET_PG));
#endif
    return i_data.getBit<TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
