/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00063.H $         */
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

#ifndef __IOHS_REG00063_H_
#define __IOHS_REG00063_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL,
           IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL,
           IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL,
           IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_COUNT_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_BERPL_PRBS_SEED_DONE_B_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]

//>> CLEAR_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]
static inline bool GET_IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_BIT_REGS_STAT4_PL_ERR_TRAPPED_RO_SIGNAL]

//>> PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000]

//>> PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL]

//>> PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL]


//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010]

//>> SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010]

//>> GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010,
           IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010]

//>> PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]
static inline bool GET_IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B]

//>> PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL]

//>> PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK]

//>> SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK]

//>> GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK]

//>> PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111]

//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111]

//>> PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001]

//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001]

//>> PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011]

//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011]

//>> PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001]

//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001]

//>> PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011]

//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011]

//>> PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL]

//>> PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL]


//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000]

//>> SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000]

//>> GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101]

//>> PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL]

//>> PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL]


//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_DATA]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]

//>> SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]
static inline fapi2::buffer<uint64_t>& SET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]

//>> GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]
static inline fapi2::buffer<uint64_t>& GET_IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE,
           IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL14_PL_EDGE]

//>> PREP_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL]

//>> PUT_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL]


//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline bool GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline bool GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> PREP_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL]

//>> PUT_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL]


//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]

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

//>> PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL]

//>> PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL]


//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_EN]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL19_PL_SEL]

//>> PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL]

//>> PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL]


//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN]

//>> PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL]

//>> PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL]


//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL]

//>> PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL]


//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL]

//>> PREP_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL]

//>> PUT_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL]


//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN]

//>> PREP_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL]

//>> PUT_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL]


//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN,
           IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN,
           IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN,
           IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_EN]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL5_PL_SEL]

//>> PREP_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL]

//>> PUT_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL]


//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_CTRL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> CLEAR_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline bool GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> CLEAR_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline bool GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> CLEAR_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline bool GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]

//>> SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]

//>> GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL,
           IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_3_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]

//>> PREP_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL]

//>> PUT_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL]


//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> CLEAR_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline bool GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> PREP_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL]

//>> PUT_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL]


//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]

//>> PREP_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL]

//>> PUT_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL]


//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_EN]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL]

//>> SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL]

//>> GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL6_PL_SEL]

//>> PREP_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL]

//>> PUT_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL]


//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> PREP_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL]

//>> PUT_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL]


//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]

//>> PREP_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL]

//>> PUT_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL]


//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]

//>> CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]
static inline bool GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_RESET]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline bool GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> PREP_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL]

//>> PUT_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL]


//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL,
           IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL,
           IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL,
           IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL,
           IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL,
           IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL,
           IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]

//>> PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL]

//>> PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL]


//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]

//>> PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL]

//>> PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL]


//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_EN]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL6_PL_SEL]

//>> PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL]

//>> PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL]


//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ,
           IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ]

//>> PREP_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL]

//>> PUT_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL]


//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN,
           IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN,
           IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN,
           IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_EN]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL,
           IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL,
           IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL,
           IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]

//>> PREP_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL]

//>> PUT_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL]


//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL5_PL_SEL]

//>> PREP_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL]

//>> PUT_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL]


//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_CTRL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]
static inline bool GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]
static inline bool GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]
static inline bool GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL]

//>> PREP_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL]

//>> PUT_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL]


//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> CLEAR_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline bool GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> CLEAR_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline bool GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> PREP_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL]

//>> PUT_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL]


//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]

//>> PREP_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL]

//>> PUT_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL]


//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN,
           IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN]

//>> PREP_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL]

//>> PUT_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL]


//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]

//>> SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]

//>> GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]

//>> PREP_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL]

//>> PUT_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL]


//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> PREP_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL]

//>> PUT_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL]


//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> PREP_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL]

//>> PUT_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL]


//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline bool GET_IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> PREP_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL]

//>> PUT_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL]


//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]

//>> SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]

//>> GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK,
           IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK]

//>> PREP_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL]

//>> GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL]

//>> PUT_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL]


//>> SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]

//>> SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]

//>> GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]

//>> PREP_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL]

//>> GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL]

//>> PUT_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL]


//>> SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN]

//>> SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN]

//>> GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_EN]

//>> SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL]

//>> SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL]

//>> GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL20_PL_SEL]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
