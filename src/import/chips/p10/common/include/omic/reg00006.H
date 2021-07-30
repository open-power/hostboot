/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00006.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __OMIC_REG00006_H_
#define __OMIC_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[CTL_REGS_TX_CNTL4_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL4_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_TX_CNTL4_PG]

//>> GET_[CTL_REGS_TX_CNTL4_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL4_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG]

//>> PUT_[CTL_REGS_TX_CNTL4_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_TX_CNTL4_PG]


//>> SET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]

//>> SET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]

//>> GET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_DAC_CNTL]

//>> SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> CLEAR_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> GET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> GET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]
static inline bool GET_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE]

//>> SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> CLEAR_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> GET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> GET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]
static inline bool GET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL4_PG_PHASE_SEL]

//>> PREP_[CTL_REGS_RX_MODE16_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE16_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_RX_MODE16_PG]

//>> GET_[CTL_REGS_RX_MODE16_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE16_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE16_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG]

//>> PUT_[CTL_REGS_RX_MODE16_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE16_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_RX_MODE16_PG]


//>> SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]

//>> SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]

//>> GET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0]

//>> SET_[CTL_REGS_RX_MODE16_PG_THRESH1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH1,
           CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_THRESH1]

//>> SET_[CTL_REGS_RX_MODE16_PG_THRESH1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH1,
           CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_THRESH1]

//>> GET_[CTL_REGS_RX_MODE16_PG_THRESH1]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_THRESH1,
           CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG_THRESH1]

//>> SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]

//>> SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]

//>> GET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1]

//>> SET_[CTL_REGS_RX_MODE16_PG_THRESH2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH2,
           CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_THRESH2]

//>> SET_[CTL_REGS_RX_MODE16_PG_THRESH2]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH2,
           CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_RX_MODE16_PG_THRESH2]

//>> GET_[CTL_REGS_RX_MODE16_PG_THRESH2]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_THRESH2,
           CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_RX_MODE16_PG_THRESH2]

//>> PREP_[DATASM_REGS_RX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNTL7_PG]

//>> GET_[DATASM_REGS_RX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL7_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL7_PG]

//>> PUT_[DATASM_REGS_RX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNTL7_PG]


//>> SET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
           DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]

//>> SET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
           DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]

//>> GET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
           DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
