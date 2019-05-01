/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00013.H $          */
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

#ifndef __PHB_REG00013_H_
#define __PHB_REG00013_H_

namespace scomt
{
namespace phb
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010906;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010906;
#endif
    return fapi2::getScom(i_target, ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return fapi2::putScom(i_target, ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.insertFromRight<ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.insertFromRight<ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.setBit<ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.clearBit<ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return i_data.extractToRight<ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return i_data.getBit<ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.insertFromRight<ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return o_data.insertFromRight<ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010906));
#endif
    return i_data.extractToRight<ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE,
           ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010900;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x8010900;
#endif
    return fapi2::getScom(i_target, ETUX08_RSB_SCOM_SSR_PHB4_HVIAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return fapi2::putScom(i_target, ETUX08_RSB_SCOM_SSR_PHB4_HVIAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.insertFromRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.insertFromRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.setBit<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.clearBit<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return i_data.extractToRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return i_data.getBit<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.insertFromRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.insertFromRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.setBit<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.clearBit<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return i_data.extractToRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return i_data.getBit<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.insertFromRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.insertFromRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.setBit<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.clearBit<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return i_data.extractToRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return i_data.getBit<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.insertFromRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE,
           ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return o_data.insertFromRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE,
           ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x8010900));
#endif
    return i_data.extractToRight<ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE,
           ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ETUX08_RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
