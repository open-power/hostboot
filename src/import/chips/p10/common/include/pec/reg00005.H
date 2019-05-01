/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pec/reg00005.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __PEC_REG00005_H_
#define __PEC_REG00005_H_

namespace scomt
{
namespace pec
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL1_RWX(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80f0044;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL1_RWX(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80f0044;
#endif
    return fapi2::getScom(i_target, NET_CTRL1_RWX, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL1_RWX(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return fapi2::putScom(i_target, NET_CTRL1_RWX, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL1_RWX_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80f0045;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL1_RWX_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80f0045;
#endif
    return fapi2::getScom(i_target, NET_CTRL1_RWX_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL1_RWX_WAND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return fapi2::putScom(i_target, NET_CTRL1_RWX_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL1_RWX_WOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80f0046;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL1_RWX_WOR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x80f0046;
#endif
    return fapi2::getScom(i_target, NET_CTRL1_RWX_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL1_RWX_WOR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return fapi2::putScom(i_target, NET_CTRL1_RWX_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PLL_CLKIN_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_PLL_CLKIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PLL_CLKIN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_PLL_CLKIN_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PLL_CLKIN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_PLL_CLKIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_PLL_CLKIN_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_PLL_CLKIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_PLL_CLKIN_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_PLL_CLKIN_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_PLL_CLKIN_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_PLL_CLKIN_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_CLKIN_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_DCC_BYPASS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_DCC_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_DCC_BYPASS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_DCC_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_DCC_BYPASS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_CLK_DCC_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CLK_DCC_BYPASS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_CLK_DCC_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CLK_DCC_BYPASS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_CLK_DCC_BYPASS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_CLK_DCC_BYPASS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_CLK_DCC_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DCC_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_PDLY_BYPASS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_PDLY_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_PDLY_BYPASS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_PDLY_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_PDLY_BYPASS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_CLK_PDLY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CLK_PDLY_BYPASS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_CLK_PDLY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CLK_PDLY_BYPASS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_CLK_PDLY_BYPASS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_CLK_PDLY_BYPASS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_CLK_PDLY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PDLY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_DIV_BYPASS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_DIV_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_DIV_BYPASS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_DIV_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_DIV_BYPASS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_CLK_DIV_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CLK_DIV_BYPASS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_CLK_DIV_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CLK_DIV_BYPASS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_CLK_DIV_BYPASS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_CLK_DIV_BYPASS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_CLK_DIV_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_DIV_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_REFCLK_CLKMUX0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_REFCLK_CLKMUX0_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_REFCLK_CLKMUX0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_REFCLK_CLKMUX0_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_REFCLK_CLKMUX0_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_REFCLK_CLKMUX0_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_REFCLK_CLKMUX0_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_REFCLK_CLKMUX0_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_REFCLK_CLKMUX0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_REFCLK_CLKMUX0_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_REFCLK_CLKMUX0_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_REFCLK_CLKMUX0_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_REFCLK_CLKMUX1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_REFCLK_CLKMUX1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_REFCLK_CLKMUX1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_REFCLK_CLKMUX1_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_REFCLK_CLKMUX1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_REFCLK_CLKMUX1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_REFCLK_CLKMUX1_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_REFCLK_CLKMUX1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_REFCLK_CLKMUX1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_REFCLK_CLKMUX1_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_REFCLK_CLKMUX1_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_REFCLK_CLKMUX1_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_REFCLK_CLKMUX1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PLL_BNDY_BYPASS_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_PLL_BNDY_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PLL_BNDY_BYPASS_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_PLL_BNDY_BYPASS_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PLL_BNDY_BYPASS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_PLL_BNDY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_PLL_BNDY_BYPASS_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_PLL_BNDY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_PLL_BNDY_BYPASS_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_PLL_BNDY_BYPASS_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_PLL_BNDY_BYPASS_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_PLL_BNDY_BYPASS_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_PLL_BNDY_BYPASS_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_DPLL_TEST_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_DPLL_TEST_SEL,
           NET_CTRL1_DPLL_TEST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_DPLL_TEST_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_DPLL_TEST_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_DPLL_TEST_SEL,
           NET_CTRL1_DPLL_TEST_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_DPLL_TEST_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_DPLL_TEST_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_DPLL_TEST_SEL,
           NET_CTRL1_DPLL_TEST_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_DPLL_TEST_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_SB_STRENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_SB_STRENGTH,
           NET_CTRL1_SB_STRENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SB_STRENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_SB_STRENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_SB_STRENGTH,
           NET_CTRL1_SB_STRENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SB_STRENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_SB_STRENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_SB_STRENGTH,
           NET_CTRL1_SB_STRENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SB_STRENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_ASYNC_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_ASYNC_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_ASYNC_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_ASYNC_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_ASYNC_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_ASYNC_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_ASYNC_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_ASYNC_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_ASYNC_OBS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_ASYNC_OBS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_ASYNC_OBS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_ASYNC_OBS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_ASYNC_OBS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_ASYNC_OBS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_ASYNC_OBS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_ASYNC_OBS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_ASYNC_OBS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CPM_CAL_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CPM_CAL_SET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CPM_CAL_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_CPM_CAL_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_CPM_CAL_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_CPM_CAL_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_CPM_CAL_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_CPM_CAL_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CPM_CAL_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_SENSEADJ_RESET0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_SENSEADJ_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_SENSEADJ_RESET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_SENSEADJ_RESET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_SENSEADJ_RESET0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_SENSEADJ_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_SENSEADJ_RESET0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_SENSEADJ_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_SENSEADJ_RESET0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_SENSEADJ_RESET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_SENSEADJ_RESET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_SENSEADJ_RESET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_SENSEADJ_RESET1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_SENSEADJ_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_SENSEADJ_RESET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_SENSEADJ_RESET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_SENSEADJ_RESET1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_SENSEADJ_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_SENSEADJ_RESET1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_SENSEADJ_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_SENSEADJ_RESET1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_SENSEADJ_RESET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_SENSEADJ_RESET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_SENSEADJ_RESET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_SENSEADJ_RESET1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_PULSE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_PULSE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_PULSE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.setBit<NET_CTRL1_CLK_PULSE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.clearBit<NET_CTRL1_CLK_PULSE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_CLK_PULSE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NET_CTRL1_CLK_PULSE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.getBit<NET_CTRL1_CLK_PULSE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PULSE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_PULSE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_PULSE_MODE,
           NET_CTRL1_CLK_PULSE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PULSE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CLK_PULSE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return o_data.insertFromRight<NET_CTRL1_CLK_PULSE_MODE,
           NET_CTRL1_CLK_PULSE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PULSE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CLK_PULSE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x80f0046, 0x80f0045, 0x80f0044));
#endif
    return i_data.extractToRight<NET_CTRL1_CLK_PULSE_MODE,
           NET_CTRL1_CLK_PULSE_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NET_CTRL1_CLK_PULSE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
