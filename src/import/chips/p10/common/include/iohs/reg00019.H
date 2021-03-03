/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00019.H $         */
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

#ifndef __IOHS_REG00019_H_
#define __IOHS_REG00019_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG;
#endif
    return fapi2::getScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]

//>> PUT_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return fapi2::putScom(i_target, IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]


//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC,
           IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& SET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& CLEAR_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline bool GET_IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
