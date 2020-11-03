/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00051.H $         */
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

#ifndef __PROC_REG00051_H_
#define __PROC_REG00051_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PSI_MAC_SCOM_REGS_RX_CNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PSI_MAC_SCOM_REGS_RX_CNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSI_MAC_SCOM_REGS_RX_CNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PSI_MAC_SCOM_REGS_RX_CNTL]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PSI_MAC_SCOM_REGS_RX_CNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSI_MAC_SCOM_REGS_RX_CNTL;
#endif
    return fapi2::getScom(i_target, PSI_MAC_SCOM_REGS_RX_CNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL]

//>> PUT_[PSI_MAC_SCOM_REGS_RX_CNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PSI_MAC_SCOM_REGS_RX_CNTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return fapi2::putScom(i_target, PSI_MAC_SCOM_REGS_RX_CNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PSI_MAC_SCOM_REGS_RX_CNTL]


//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_IORESET_WO_PULSE_SLOW_SIGNAL]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]

//>> CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]
static inline bool GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_CHECK_EN]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PATTERN_SEL]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]

//>> CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]
static inline bool GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]

//>> CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]
static inline bool GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_LANE_INVERT]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]

//>> CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]
static inline bool GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_PDWN]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_CLK_DLY]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DATA_DLY]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_CLK_DLY]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY]

//>> SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY]

//>> GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_CNTL));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY,
           PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_CNTL_RX_PSI_DEGLITCH_DATA_DLY]

//>> PREP_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG]

//>> PUT_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG]


//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline bool GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline bool GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline bool GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline bool GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline bool GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline bool GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2,
           TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline bool GET_TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> PREP_[TP_TPBR_AD_LPC_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_LPC_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_LPC_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_LPC_STATUS_REG]

//>> GET_[TP_TPBR_AD_LPC_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_LPC_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_LPC_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_LPC_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_STATUS_REG]

//>> PUT_[TP_TPBR_AD_LPC_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_LPC_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_LPC_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_LPC_STATUS_REG]


//>> SET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]

//>> SET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]

//>> SET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]

//>> CLEAR_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]

//>> GET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]

//>> GET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]
static inline bool GET_TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS]

//>> SET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]

//>> SET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]

//>> SET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]

//>> CLEAR_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]

//>> GET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]

//>> GET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]
static inline bool GET_TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_STATUS_REG_VALID_STATUS]

//>> SET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]

//>> SET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]

//>> SET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]

//>> CLEAR_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]

//>> GET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]

//>> GET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]
static inline bool GET_TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_STATUS_REG_ACK_STATUS]

//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRACT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIRACT0]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRACT0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRACT0]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIRACT0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRACT0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIRACT0]


//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRACT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0,
           TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRACT0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0,
           TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRACT0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0,
           TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRACT0_PBAFIRACT0_FIR_ACTION0]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAERRRPT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAERRRPT2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAERRRPT2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAERRRPT2]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAERRRPT2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAERRRPT2;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAERRRPT2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAERRRPT2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAERRRPT2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAERRRPT2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAERRRPT2]


//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_SLV_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCDE_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_BCUE_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_BAR_PARITY_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXPUSH_WRERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAERRRPT2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR,
           TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAERRRPT2_CERR_AXIPUSH_WRERR]

//>> PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBARBUFVAL5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL5]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBARBUFVAL5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL5;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5]

//>> PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBARBUFVAL5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL5]


//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL5));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL5_MASTERID]

//>> PREP_[TP_TPBR_PBA_PBAO_PBASLVCTL2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBASLVCTL2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBASLVCTL2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBASLVCTL2]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBASLVCTL2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBASLVCTL2;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBASLVCTL2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2]

//>> PUT_[TP_TPBR_PBA_PBAO_PBASLVCTL2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBASLVCTL2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBASLVCTL2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBASLVCTL2]


//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_11_14]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_INVALIDATE_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_23]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_DIS_WRITE_GATHER]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TSIZE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR,
           TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_EXTADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL2));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL2_RESERVED_50]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAXCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAXCFG]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXCFG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAXCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXCFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAXCFG]


//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_PBAX_EN]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVATION_EN]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RESET]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_RESET]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_11]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV,
           TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26,
           TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26,
           TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26,
           TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_RESERVED_25_26]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH,
           TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH,
           TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH,
           TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV,
           TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV,
           TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV,
           TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
