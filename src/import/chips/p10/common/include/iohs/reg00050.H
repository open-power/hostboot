/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00050.H $         */
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

#ifndef __IOHS_REG00050_H_
#define __IOHS_REG00050_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL]

//>> PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL]


//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL]

//>> PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL]


//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL]

//>> PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL]


//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_EN]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]

//>> PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL]

//>> PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL]


//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]

//>> PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL]

//>> PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL]


//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]

//>> PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL]

//>> PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL]


//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline bool GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]

//>> SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]

//>> GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL,
           IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]

//>> PREP_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL]

//>> PUT_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL]


//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
