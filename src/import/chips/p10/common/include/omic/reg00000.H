/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00000.H $         */
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

#ifndef __OMIC_REG00000_H_
#define __OMIC_REG00000_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[DATASM_REGS_RX_CNTL8_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL8_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DATASM_REGS_RX_CNTL8_PG]

//>> GET_[DATASM_REGS_RX_CNTL8_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL8_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL8_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL8_PG]

//>> PUT_[DATASM_REGS_RX_CNTL8_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL8_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL8_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL8_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DATASM_REGS_RX_CNTL8_PG]


//>> SET_[DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL8_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23,
           DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23]

//>> SET_[DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23]
static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL8_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23,
           DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23]

//>> GET_[DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23]
static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL8_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23,
           DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
