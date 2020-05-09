/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00007.H $         */
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

#ifndef __IOHS_REG00007_H_
#define __IOHS_REG00007_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL]

//>> PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL]


//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> CLEAR_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
CLEAR_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline fapi2::buffer<uint64_t>&
GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]
static inline bool GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL]

//>> PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL]

//>> PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL]


//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_EN]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL]

//>> SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL]

//>> GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL,
           IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL21_PL_SEL]

//>> PREP_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL]

//>> PUT_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL]


//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> PREP_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL]

//>> PUT_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL]


//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> PREP_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL]

//>> PUT_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL]


//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline bool GET_IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> PREP_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL]

//>> PUT_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL]


//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_EN]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL,
           IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL7_PL_SEL]

//>> PREP_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL]

//>> PUT_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL]


//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline bool GET_IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_0_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> PREP_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL]

//>> PUT_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL]


//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE,
           IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE,
           IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]
static inline bool GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]
static inline bool GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]
static inline bool GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL]

//>> PREP_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL]

//>> PUT_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL]


//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN]

//>> PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL]

//>> PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL]


//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN]

//>> PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL]

//>> PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL]


//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_EN]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL,
           IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL20_PL_SEL]

//>> PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL]

//>> PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL]


//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]

//>> SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]

//>> CLEAR_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]

//>> GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]
static inline bool GET_IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE]

//>> PREP_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL]

//>> PUT_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL]


//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]
static inline bool GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]
static inline bool GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]
static inline bool GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]
static inline bool GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]
static inline bool GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]
static inline bool GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]
static inline bool GET_IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE]

//>> PREP_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL]

//>> PUT_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL]


//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]

//>> CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]
static inline bool GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT,
           IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_PAT]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]

//>> SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.setBit<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]

//>> CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return o_data.clearBit<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.extractToRight<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]

//>> GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]
static inline bool GET_IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL));
#endif
    return i_data.getBit<IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL17_PL_DCC_CMP_RUN]

//>> PREP_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL]

//>> PUT_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL]


//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> CLEAR_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]
static inline bool GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE]

//>> PREP_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL]

//>> PUT_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL]


//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN]

//>> PREP_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL]

//>> PUT_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL]


//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_EN]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL]

//>> SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL]

//>> GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL,
           IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL6_PL_SEL]

//>> PREP_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL]

//>> GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL]

//>> PUT_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL]


//>> SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]

//>> SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]

//>> GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN,
           IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN]

//>> PREP_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL]

//>> PUT_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL]


//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN,
           IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN,
           IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN,
           IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_EN]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL,
           IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL,
           IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL,
           IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL22_PL_SEL]

//>> PREP_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL]

//>> PUT_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL]


//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]

//>> CLEAR_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]
static inline bool GET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_RESET]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> CLEAR_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]
static inline bool GET_IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL2_PL_DOM_IORESET]

//>> PREP_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL]

//>> PUT_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL]


//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL,
           IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL,
           IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL,
           IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL,
           IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL,
           IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL,
           IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_3_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL]

//>> PREP_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL]

//>> PUT_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL]


//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]
static inline bool GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]
static inline bool GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM]

//>> PREP_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL]

//>> PUT_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL]


//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN,
           IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN]

//>> PREP_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL]

//>> PUT_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL]


//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]
static inline bool GET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]
static inline bool GET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL,
           IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]
static inline bool GET_IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_2_DD_5_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL]

//>> PREP_[RECOV_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RECOV_INTERRUPT_REG]

//>> GET_[RECOV_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RECOV_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, RECOV_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RECOV_INTERRUPT_REG]

//>> PUT_[RECOV_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RECOV_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, RECOV_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RECOV_INTERRUPT_REG]


//>> SET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<RECOV_INTERRUPT_REG_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_INTERRUPT_REG_RECOV]

//>> SET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_INTERRUPT_REG_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<RECOV_INTERRUPT_REG_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_INTERRUPT_REG_RECOV]

//>> SET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.setBit<RECOV_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RECOV_INTERRUPT_REG_RECOV]

//>> CLEAR_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& CLEAR_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return o_data.clearBit<RECOV_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RECOV_INTERRUPT_REG_RECOV]

//>> GET_[RECOV_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& GET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return i_data.extractToRight<RECOV_INTERRUPT_REG_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_INTERRUPT_REG_RECOV]

//>> GET_[RECOV_INTERRUPT_REG_RECOV]
static inline bool GET_RECOV_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RECOV_INTERRUPT_REG));
#endif
    return i_data.getBit<RECOV_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access RECOV_INTERRUPT_REG_RECOV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RECOV_INTERRUPT_REG_RECOV]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
