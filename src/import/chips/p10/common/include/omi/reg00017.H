/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00017.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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

#ifndef __OMI_REG00017_H_
#define __OMI_REG00017_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL]

//>> PUT_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL]


//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]

//>> PREP_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL]

//>> PUT_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL]


//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
