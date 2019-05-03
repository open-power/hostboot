/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00002.H $          */
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

#ifndef __PHB_REG00002_H_
#define __PHB_REG00002_H_

namespace scomt
{
namespace phb
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_CERR_RPT0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CERR_RPT0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_CERR_RPT0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CERR_RPT0_REG;
#endif
    return fapi2::getScom(i_target, REGS_CERR_RPT0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_CERR_RPT0_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT0_REG));
#endif
    return fapi2::putScom(i_target, REGS_CERR_RPT0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_CERR_RPT0_REG_CERR_RPT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT0_REG));
#endif
    return o_data.insertFromRight<REGS_CERR_RPT0_REG_CERR_RPT0,
           REGS_CERR_RPT0_REG_CERR_RPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_CERR_RPT0_REG_CERR_RPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_CERR_RPT0_REG_CERR_RPT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT0_REG));
#endif
    return o_data.insertFromRight<REGS_CERR_RPT0_REG_CERR_RPT0,
           REGS_CERR_RPT0_REG_CERR_RPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_CERR_RPT0_REG_CERR_RPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_CERR_RPT0_REG_CERR_RPT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT0_REG));
#endif
    return i_data.extractToRight<REGS_CERR_RPT0_REG_CERR_RPT0,
           REGS_CERR_RPT0_REG_CERR_RPT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_CERR_RPT0_REG_CERR_RPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_CERR_RPT1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CERR_RPT1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_CERR_RPT1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_CERR_RPT1_REG;
#endif
    return fapi2::getScom(i_target, REGS_CERR_RPT1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_CERR_RPT1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT1_REG));
#endif
    return fapi2::putScom(i_target, REGS_CERR_RPT1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_CERR_RPT1_REG_CERR_RPT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT1_REG));
#endif
    return o_data.insertFromRight<REGS_CERR_RPT1_REG_CERR_RPT1,
           REGS_CERR_RPT1_REG_CERR_RPT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_CERR_RPT1_REG_CERR_RPT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_CERR_RPT1_REG_CERR_RPT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT1_REG));
#endif
    return o_data.insertFromRight<REGS_CERR_RPT1_REG_CERR_RPT1,
           REGS_CERR_RPT1_REG_CERR_RPT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_CERR_RPT1_REG_CERR_RPT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_CERR_RPT1_REG_CERR_RPT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_CERR_RPT1_REG));
#endif
    return i_data.extractToRight<REGS_CERR_RPT1_REG_CERR_RPT1,
           REGS_CERR_RPT1_REG_CERR_RPT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_CERR_RPT1_REG_CERR_RPT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_SCOM_SSR_PHB4_HVIAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB4_HVIAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_SCOM_SSR_PHB4_HVIAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB4_HVIAR;
#endif
    return fapi2::getScom(i_target, RSB_SCOM_SSR_PHB4_HVIAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_SCOM_SSR_PHB4_HVIAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return fapi2::putScom(i_target, RSB_SCOM_SSR_PHB4_HVIAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
