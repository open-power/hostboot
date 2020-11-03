/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00047.H $         */
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

#ifndef __PROC_REG00047_H_
#define __PROC_REG00047_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PSI_MAC_SCOM_REGS_TX_CNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PSI_MAC_SCOM_REGS_TX_CNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSI_MAC_SCOM_REGS_TX_CNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PSI_MAC_SCOM_REGS_TX_CNTL]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PSI_MAC_SCOM_REGS_TX_CNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSI_MAC_SCOM_REGS_TX_CNTL;
#endif
    return fapi2::getScom(i_target, PSI_MAC_SCOM_REGS_TX_CNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL]

//>> PUT_[PSI_MAC_SCOM_REGS_TX_CNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PSI_MAC_SCOM_REGS_TX_CNTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return fapi2::putScom(i_target, PSI_MAC_SCOM_REGS_TX_CNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PSI_MAC_SCOM_REGS_TX_CNTL]


//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]

//>> CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]
static inline bool GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_DRV_PATTERN_EN]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PATTERN_SEL]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_P]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_QUIESCE_N]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_QUIESCE]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]

//>> CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]
static inline bool GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CLK_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]

//>> CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]
static inline bool GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_LANE_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]

//>> CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]
static inline bool GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_PDWN]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]

//>> CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]
static inline bool GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_BIST_EN]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE]

//>> SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE]

//>> GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_TX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE,
           PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_TX_CNTL_TX_PSI_CNTL_SPARE]

//>> PREP_[TP_TCN1_N1_LOCAL_FIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_FIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_LOCAL_FIR_RW]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_FIR_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_LOCAL_FIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_RW]

//>> PUT_[TP_TCN1_N1_LOCAL_FIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_LOCAL_FIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_LOCAL_FIR_RW]

//>> PREP_[TP_TCN1_N1_LOCAL_FIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_FIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_LOCAL_FIR_WO_AND]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_FIR_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_LOCAL_FIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_WO_AND]

//>> PUT_[TP_TCN1_N1_LOCAL_FIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_LOCAL_FIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_LOCAL_FIR_WO_AND]

//>> PREP_[TP_TCN1_N1_LOCAL_FIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_FIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_LOCAL_FIR_WO_OR]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_FIR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_LOCAL_FIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_WO_OR]

//>> PUT_[TP_TCN1_N1_LOCAL_FIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_LOCAL_FIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_LOCAL_FIR_WO_OR]


//>> SET_[TP_TCN1_N1_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_CFIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CFIR]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CFIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_CFIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CFIR]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CFIR]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_CFIR]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_CFIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_CFIR]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_CFIR]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_CFIR]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_CPLT_CTRL]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_CC_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CC_PCB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_CC_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_CC_PCB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_CC_PCB]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_CC_OTHERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CC_OTHERS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_CC_OTHERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_CC_OTHERS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_CC_OTHERS]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN04]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN04]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN04]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN04]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN04]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN04]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN04]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN05]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN05]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN05]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN05]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN05]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN05]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN05]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN06]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN06]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN06]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN06]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN06]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN06]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN06]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN07]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN07]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN07]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN07]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN07]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN07]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN07]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN08]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN08]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN08]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN08]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN08]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN08]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN08]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN09]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN09]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN09]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN09]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN09]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN09]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN09]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN10]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN10]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN10]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN10]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN10]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN10]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN10]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN11]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN11]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN11]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN11]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN11]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN11]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN11]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN12]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN12]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN12]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN12]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN12]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN12]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN12]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN13]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN13]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN13]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN13]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN13]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN13]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN13]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN14]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN14]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN14]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN14]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN14]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN14]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN14]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN15]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN15]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN15]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN15]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN15]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN15]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN15]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN16]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN16]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN16]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN16]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN16]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN16]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN16]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN17]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN17]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN17]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN17]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN17]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN17]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN17]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN18]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN18]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN18]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN18]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN18]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN18]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN18]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN19]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN19]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN19]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN19]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN19]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN19]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN19]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN20]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN20]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN20]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN20]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN20]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN20]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN20]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN21]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN21]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN21]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN21]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN21]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN21]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN21]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN22]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN22]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN22]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN22]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN22]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN22]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN22]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN23]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN23]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN23]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN23]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN23]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN23]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN23]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN24]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN24]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN24]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN24]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN24]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN24]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN24]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN25]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN25]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN25]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN25]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN25]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN25]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN25]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN26]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN26]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN26]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN26]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN26]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN26]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN26]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN27]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN27]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN27]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN27]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN27]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN27]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN27]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN28]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN28]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN28]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN28]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN28]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN28]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN28]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN29]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN29]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN29]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN29]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN29]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN29]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN29]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN30]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN30]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN30]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN30]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN30]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN30]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN30]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN31]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN31]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN31]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN31]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN31]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN31]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN31]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN32]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN32]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN32]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN32]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN32]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN32]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN32]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN33]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN33]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN33]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN33]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN33]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN33]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN33]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN34]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN34]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN34]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN34]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN34]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN34]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN34]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN35]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN35]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN35]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN35]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN35]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN35]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN35]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN36]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN36]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN36]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN36]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN36]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN36]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN36]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN37]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN37]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN37]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN37]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN37]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN37]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN37]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN38]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN38]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN38]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN38]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN38]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN38]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN38]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN39]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN39]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN39]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN39]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN39]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN39]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN39]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN40]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN40]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN40]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN40]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN40]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN40]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN40]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN41]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN41]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN41]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN41]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN41]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN41]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN41]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN42]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN42]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN42]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN42]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN42]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN42]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN42]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN43]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN43]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN43]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN43]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN43]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN43]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN43]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN44]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN44]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN44]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN44]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN44]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN44]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN44]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN45]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN45]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN45]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN45]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN45]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN45]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN45]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN46]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN46]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN46]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN46]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN46]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN46]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN46]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN47]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN47]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN47]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN47]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN47]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN47]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN47]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN48]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN48]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN48]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN48]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN48]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN48]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN48]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN49]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN49]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN49]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN49]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN49]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN49]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN49]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN50]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN50]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN50]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN50]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN50]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN50]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN50]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN51]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN51]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN51]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN51]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN51]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN51]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN51]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN52]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN52]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN52]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN52]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN52]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN52]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN52]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN53]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN53]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN53]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN53]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN53]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN53]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN53]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN54]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN54]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN54]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN54]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN54]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN54]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN54]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN55]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN55]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN55]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN55]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN55]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN55]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN55]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN56]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN56]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN56]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN56]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN56]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN56]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN56]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN57]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN57]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN57]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN57]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN57]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN57]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN57]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN58]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN58]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN58]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN58]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN58]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN58]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN58]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN59]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN59]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN59]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN59]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN59]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN59]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN59]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN60]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN60]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN60]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN60]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN60]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN60]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN60]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN61]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN61]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN61]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN61]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN61]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN61]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN61]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN62]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_IN62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN62]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_IN62]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_IN62]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_IN62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN62]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_IN62]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_IN62]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> SET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> CLEAR_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> GET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline bool GET_TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_FIR_RW, TP_TCN1_N1_LOCAL_FIR_WO_AND, TP_TCN1_N1_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> PREP_[TP_TPBR_AD_LPC_BASE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_LPC_BASE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_LPC_BASE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_LPC_BASE_REG]

//>> GET_[TP_TPBR_AD_LPC_BASE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_LPC_BASE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_LPC_BASE_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_LPC_BASE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_BASE_REG]

//>> PUT_[TP_TPBR_AD_LPC_BASE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_LPC_BASE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_LPC_BASE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_LPC_BASE_REG]


//>> SET_[TP_TPBR_AD_LPC_BASE_REG_BASE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_BASE_REG_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_BASE_REG_BASE,
           TP_TPBR_AD_LPC_BASE_REG_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_LPC_BASE_REG_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_BASE_REG_BASE]

//>> SET_[TP_TPBR_AD_LPC_BASE_REG_BASE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_BASE_REG_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_BASE_REG_BASE,
           TP_TPBR_AD_LPC_BASE_REG_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_LPC_BASE_REG_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_BASE_REG_BASE]

//>> GET_[TP_TPBR_AD_LPC_BASE_REG_BASE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_LPC_BASE_REG_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_LPC_BASE_REG_BASE,
           TP_TPBR_AD_LPC_BASE_REG_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_LPC_BASE_REG_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_BASE_REG_BASE]

//>> SET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_BASE_REG_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_LPC_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]

//>> SET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_BASE_REG_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_BASE_REG_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_LPC_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]

//>> SET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_LPC_BASE_REG_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_LPC_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]

//>> CLEAR_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_LPC_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_LPC_BASE_REG_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_LPC_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]

//>> GET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_LPC_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_LPC_BASE_REG_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_LPC_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]

//>> GET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]
static inline bool GET_TP_TPBR_AD_LPC_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_BASE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_LPC_BASE_REG_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_LPC_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_BASE_REG_DISABLE]

//>> PREP_[TP_TPBR_PBA_PBAO_PBABAR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABAR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBABAR2]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABAR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR2;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABAR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR2]

//>> PUT_[TP_TPBR_PBA_PBAO_PBABAR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABAR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABAR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBABAR2]


//>> SET_[TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR2_CMD_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]
static inline bool GET_TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR2_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR2_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR2_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR2_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR2_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR2_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR2_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR2_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR2_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR2_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR2_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR2_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR2_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR2_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR2_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR2_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR2_VTARGET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR2_VTARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR2_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR2_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR2_VTARGET]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR2_VTARGET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR2_VTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR2_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR2_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR2_VTARGET]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR2_VTARGET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR2_VTARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR2_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR2_VTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR2_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR2_VTARGET]

//>> PREP_[TP_TPBR_PBA_PBAO_PBABARMSK3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABARMSK3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBABARMSK3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABARMSK3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABARMSK3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK3;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABARMSK3]

//>> PUT_[TP_TPBR_PBA_PBAO_PBABARMSK3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABARMSK3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK3));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBABARMSK3]


//>> SET_[TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK]

//>> SET_[TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK]

//>> GET_[TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABARMSK3_PBABARMSK3_MSK]

//>> PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBARBUFVAL2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL2]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBARBUFVAL2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL2;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2]

//>> PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBARBUFVAL2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL2]


//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL2_MASTERID]

//>> PREP_[TP_TPBR_PSIHB_STATUS_CTL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_STATUS_CTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_STATUS_CTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSIHB_STATUS_CTL_REG]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_STATUS_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_STATUS_CTL_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_STATUS_CTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG]

//>> PUT_[TP_TPBR_PSIHB_STATUS_CTL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_STATUS_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_STATUS_CTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSIHB_STATUS_CTL_REG]

//>> PREP_[TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1]

//>> PUT_[TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1]

//>> PREP_[TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR]

//>> PUT_[TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR]


//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_CMD_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PHBCSR_SPARE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INT_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_ERR_RSP_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_RESET]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIHBC_RESET]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK,
           TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK,
           TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK,
           TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_ST_EOI_ENABLE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_CEC_PSI_INTERRUPT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INTERRUPT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_LINK_ACTIVE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_OUTBOUND_ACTIVE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INBOUND_ACTIVE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_LOAD_OUTSTANDING]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMAR_OUTSTANDING]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INT_BUSY]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_XMIT_ERROR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_LINK_INACTIVE_TRANS]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_ACK_TIMEOUT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LOAD_TIMEOUT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_LENGTH_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_ADDR_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_MMIO_TYPE_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_UE]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT1]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSI_ALERT2]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_DMA_ADDR_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_TCE_EXTENT_ERR]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_PAGE_FAULT]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_PSIFSP_INV_OP]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]

//>> SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]

//>> CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]

//>> GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]
static inline bool GET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_STATUS_CTL_REG, TP_TPBR_PSIHB_STATUS_CTL_REG_SCOM1,
                           TP_TPBR_PSIHB_STATUS_CTL_REG_WO_CLEAR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_INV_READ]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR_MCS]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_OXIXCR_XCR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXCR_XICTR_CTR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_DBG]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_XSTOP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_HALT_ON_TRIG]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_COVERAGE_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_INTR_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_EXTRA]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_TRACE_STALL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_WAIT_CYCLES]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_FULL_SPEED]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_DIS_FLOW_CHANGE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_MODE_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_MARK_TRACE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_EN_EE_TRACE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_RESERVED14_15]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_FIR_TRIGGER]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEDBG_TRACE_DATA_SEL]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
