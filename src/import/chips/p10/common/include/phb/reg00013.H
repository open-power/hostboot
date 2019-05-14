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
static inline fapi2::ReturnCode PREP_REGS_PE_DFREEZE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PE_DFREEZE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PE_DFREEZE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PE_DFREEZE_REG;
#endif
    return fapi2::getScom(i_target, REGS_PE_DFREEZE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PE_DFREEZE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PE_DFREEZE_REG));
#endif
    return fapi2::putScom(i_target, REGS_PE_DFREEZE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_PE_DFREEZE_REG_PE_DFREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_DFREEZE_REG));
#endif
    return o_data.insertFromRight<REGS_PE_DFREEZE_REG_PE_DFREEZE,
           REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_DFREEZE_REG_PE_DFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_DFREEZE_REG_PE_DFREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_DFREEZE_REG));
#endif
    return o_data.insertFromRight<REGS_PE_DFREEZE_REG_PE_DFREEZE,
           REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_DFREEZE_REG_PE_DFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PE_DFREEZE_REG_PE_DFREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_DFREEZE_REG));
#endif
    return i_data.extractToRight<REGS_PE_DFREEZE_REG_PE_DFREEZE,
           REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_DFREEZE_REG_PE_DFREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PFIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PFIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_RW;
#endif
    return fapi2::getScom(i_target, REGS_PFIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PFIR_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, REGS_PFIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PFIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PFIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, REGS_PFIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PFIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, REGS_PFIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PFIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PFIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PFIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, REGS_PFIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PFIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, REGS_PFIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_PFIR_REG_PFIRPFIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<REGS_PFIR_REG_PFIRPFIR,
           REGS_PFIR_REG_PFIRPFIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PFIR_REG_PFIRPFIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<REGS_PFIR_REG_PFIRPFIR,
           REGS_PFIR_REG_PFIRPFIR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PFIR_REG_PFIRPFIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PFIR_REG_RW, REGS_PFIR_REG_WO_AND, REGS_PFIR_REG_WO_OR));
#endif
    return i_data.extractToRight<REGS_PFIR_REG_PFIRPFIR,
           REGS_PFIR_REG_PFIRPFIR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PFIR_REG_PFIRPFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_SCOM_SSR_PHB5_HVIAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB5_HVIAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_SCOM_SSR_PHB5_HVIAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB5_HVIAR;
#endif
    return fapi2::getScom(i_target, RSB_SCOM_SSR_PHB5_HVIAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_SCOM_SSR_PHB5_HVIAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return fapi2::putScom(i_target, RSB_SCOM_SSR_PHB5_HVIAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_HVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_HVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
