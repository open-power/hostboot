/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00003.H $          */
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

#ifndef __OMI_REG00003_H_
#define __OMI_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_ZERO]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
