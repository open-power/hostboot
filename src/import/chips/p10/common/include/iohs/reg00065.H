/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00065.H $         */
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

#ifndef __IOHS_REG00065_H_
#define __IOHS_REG00065_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL]

//>> PUT_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL]


//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline bool GET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline bool GET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL,
           IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL,
           IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL,
           IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline bool GET_IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> PREP_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG]

//>> GET_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG]

//>> PUT_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG]


//>> SET_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]

//>> SET_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]

//>> GET_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
           IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23]

//>> PREP_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG]

//>> GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG;
#endif
    return fapi2::getScom(i_target, IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG]

//>> PUT_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return fapi2::putScom(i_target, IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG]


//>> SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]

//>> SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]

//>> GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2]

//>> SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3]

//>> SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3]

//>> GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH3]

//>> SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]

//>> SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]

//>> GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3]

//>> SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4]

//>> SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4]

//>> GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4,
           IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_RXCTL_CTL_REGS_RX_MODE17_PG_THRESH4]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
