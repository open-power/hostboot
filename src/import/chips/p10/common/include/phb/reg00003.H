/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00003.H $          */
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

#ifndef __PHB_REG00003_H_
#define __PHB_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_NFIRACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_NFIRACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRACTION0_REG;
#endif
    return fapi2::getScom(i_target, REGS_NFIRACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_NFIRACTION0_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_NFIRACTION0_REG));
#endif
    return fapi2::putScom(i_target, REGS_NFIRACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_NFIRACTION0_REG_NFIRACTION0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_NFIRACTION0_REG));
#endif
    return o_data.insertFromRight<REGS_NFIRACTION0_REG_NFIRACTION0,
           REGS_NFIRACTION0_REG_NFIRACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_NFIRACTION0_REG_NFIRACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_NFIRACTION0_REG_NFIRACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_NFIRACTION0_REG));
#endif
    return o_data.insertFromRight<REGS_NFIRACTION0_REG_NFIRACTION0,
           REGS_NFIRACTION0_REG_NFIRACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_NFIRACTION0_REG_NFIRACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_NFIRACTION0_REG_NFIRACTION0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_NFIRACTION0_REG));
#endif
    return i_data.extractToRight<REGS_NFIRACTION0_REG_NFIRACTION0,
           REGS_NFIRACTION0_REG_NFIRACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_NFIRACTION0_REG_NFIRACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_NFIRACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_NFIRACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_NFIRACTION1_REG;
#endif
    return fapi2::getScom(i_target, REGS_NFIRACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_NFIRACTION1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_NFIRACTION1_REG));
#endif
    return fapi2::putScom(i_target, REGS_NFIRACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_NFIRACTION1_REG_NFIRACTION1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_NFIRACTION1_REG));
#endif
    return o_data.insertFromRight<REGS_NFIRACTION1_REG_NFIRACTION1,
           REGS_NFIRACTION1_REG_NFIRACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_NFIRACTION1_REG_NFIRACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_NFIRACTION1_REG_NFIRACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_NFIRACTION1_REG));
#endif
    return o_data.insertFromRight<REGS_NFIRACTION1_REG_NFIRACTION1,
           REGS_NFIRACTION1_REG_NFIRACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_NFIRACTION1_REG_NFIRACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_NFIRACTION1_REG_NFIRACTION1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_NFIRACTION1_REG));
#endif
    return i_data.extractToRight<REGS_NFIRACTION1_REG_NFIRACTION1,
           REGS_NFIRACTION1_REG_NFIRACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_NFIRACTION1_REG_NFIRACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_RESERVED1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_RESERVED1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_RESERVED1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_RESERVED1_REG;
#endif
    return fapi2::getScom(i_target, REGS_RESERVED1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_RESERVED1_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_RESERVED1_REG));
#endif
    return fapi2::putScom(i_target, REGS_RESERVED1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_WOF_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_WOF_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_WOF_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_WOF_REG;
#endif
    return fapi2::getScom(i_target, RSB_REGS_WOF_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_WOF_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_WOF_REG));
#endif
    return fapi2::putScom(i_target, RSB_REGS_WOF_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR;
#endif
    return fapi2::getScom(i_target, RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return fapi2::putScom(i_target, RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN,
           RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN,
           RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN,
           RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE,
           RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE,
           RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE,
           RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
