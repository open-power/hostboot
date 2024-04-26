/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00056.H $         */
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

#ifndef __IOHS_REG00056_H_
#define __IOHS_REG00056_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::getScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL]

//>> PUT_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return fapi2::putScom(i_target, IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL]


//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY,
           IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]

//>> CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]
static inline bool GET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]

//>> CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]
static inline bool GET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL,
           IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]

//>> SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]

//>> CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]

//>> GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]
static inline bool GET_IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
