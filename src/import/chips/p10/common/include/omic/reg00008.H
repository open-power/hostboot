/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00008.H $         */
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

#ifndef __OMIC_REG00008_H_
#define __OMIC_REG00008_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> PREP_[CTL_REGS_TX_MODE1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_MODE1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_TX_MODE1_PG]

//>> GET_[CTL_REGS_TX_MODE1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_MODE1_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_MODE1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG]

//>> PUT_[CTL_REGS_TX_MODE1_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_MODE1_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_MODE1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_TX_MODE1_PG]


//>> SET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> SET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> SET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> CLEAR_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> GET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> GET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]
static inline bool GET_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN]

//>> SET_[CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_RCTRL]

//>> SET_[CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_RCTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_RCTRL]

//>> SET_[CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_RCTRL]

//>> CLEAR_[CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_MODE1_PG_RCTRL]

//>> GET_[CTL_REGS_TX_MODE1_PG_RCTRL]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_RCTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_RCTRL]

//>> GET_[CTL_REGS_TX_MODE1_PG_RCTRL]
static inline bool GET_CTL_REGS_TX_MODE1_PG_RCTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_MODE1_PG_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_RCTRL]

//>> SET_[CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_16TO1]

//>> SET_[CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_16TO1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_16TO1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_16TO1]

//>> SET_[CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_16TO1]

//>> CLEAR_[CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_MODE1_PG_16TO1]

//>> GET_[CTL_REGS_TX_MODE1_PG_16TO1]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_16TO1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_16TO1]

//>> GET_[CTL_REGS_TX_MODE1_PG_16TO1]
static inline bool GET_CTL_REGS_TX_MODE1_PG_16TO1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_MODE1_PG_16TO1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_16TO1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_16TO1]

//>> SET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> SET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> SET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> CLEAR_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> GET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_BIST_DCC_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> GET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]
static inline bool GET_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_MODE1_PG_BIST_DCC_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_DCC_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_BIST_DCC_EN]

//>> SET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> SET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> SET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> CLEAR_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> GET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_BIST_LS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> GET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]
static inline bool GET_CTL_REGS_TX_MODE1_PG_BIST_LS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_MODE1_PG_BIST_LS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_LS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_BIST_LS_EN]

//>> SET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> SET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> SET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> CLEAR_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> GET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_BIST_HS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> GET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]
static inline bool GET_CTL_REGS_TX_MODE1_PG_BIST_HS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_MODE1_PG_BIST_HS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_BIST_HS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_BIST_HS_EN]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC,
           CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC,
           CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]

//>> GET_[CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC,
           CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC,
           CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC,
           CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]

//>> GET_[CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC,
           CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_IREF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_IREF_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_MODE1_PG_IREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> CLEAR_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_MODE1_PG_IREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> GET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_IREF_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> GET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]
static inline bool GET_CTL_REGS_TX_MODE1_PG_IREF_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_MODE1_PG_IREF_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_IREF_BYPASS]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_IREF_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_MODE1_PG_IREF_PDWN_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> SET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_MODE1_PG_IREF_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> CLEAR_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_MODE1_PG_IREF_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> GET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_MODE1_PG_IREF_PDWN_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> GET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]
static inline bool GET_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_MODE1_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_MODE1_PG_IREF_PDWN_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omic Invalid dial access CTL_REGS_TX_MODE1_PG_IREF_PDWN_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_MODE1_PG_IREF_PDWN_B]

//>> PREP_[CTL_REGS_TX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CTL_REGS_TX_CNTL7_PG]

//>> GET_[CTL_REGS_TX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL7_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL7_PG]

//>> PUT_[CTL_REGS_TX_CNTL7_PG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL7_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CTL_REGS_TX_CNTL7_PG]


//>> SET_[CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL7_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omic Invalid dial access CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]

//>> SET_[CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]
static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL7_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omic Invalid dial access CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]

//>> GET_[CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]
static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL7_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15,
           CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omic Invalid dial access CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
