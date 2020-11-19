/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00019.H $          */
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

#ifndef __OMI_REG00019_H_
#define __OMI_REG00019_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL]

//>> PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL]


//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2]

//>> SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2]
static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2]

//>> GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2]
static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2]

//>> PREP_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL]

//>> PUT_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL]


//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
