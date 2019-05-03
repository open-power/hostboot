/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00007.H $          */
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

#ifndef __PHB_REG00007_H_
#define __PHB_REG00007_H_

namespace scomt
{
namespace phb
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_MMIOBAR1_MASK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_MMIOBAR1_MASK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_MMIOBAR1_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_MMIOBAR1_MASK_REG;
#endif
    return fapi2::getScom(i_target, REGS_MMIOBAR1_MASK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_MMIOBAR1_MASK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR1_MASK_REG));
#endif
    return fapi2::putScom(i_target, REGS_MMIOBAR1_MASK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR1_MASK_REG));
#endif
    return o_data.insertFromRight<REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1,
           REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR1_MASK_REG));
#endif
    return o_data.insertFromRight<REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1,
           REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_MMIOBAR1_MASK_REG));
#endif
    return i_data.extractToRight<REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1,
           REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PBAIB_CERR_RPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PBAIB_CERR_RPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PBAIB_CERR_RPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PBAIB_CERR_RPT_REG;
#endif
    return fapi2::getScom(i_target, REGS_PBAIB_CERR_RPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PBAIB_CERR_RPT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PBAIB_CERR_RPT_REG));
#endif
    return fapi2::putScom(i_target, REGS_PBAIB_CERR_RPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIB_CERR_RPT_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0,
           REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIB_CERR_RPT_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0,
           REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIB_CERR_RPT_REG));
#endif
    return i_data.extractToRight<REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0,
           REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PE_CACHE_INJECT_CNTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PE_CACHE_INJECT_CNTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PE_CACHE_INJECT_CNTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PE_CACHE_INJECT_CNTL_REG;
#endif
    return fapi2::getScom(i_target, REGS_PE_CACHE_INJECT_CNTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PE_CACHE_INJECT_CNTL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return fapi2::putScom(i_target, REGS_PE_CACHE_INJECT_CNTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.insertFromRight<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.setBit<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return o_data.clearBit<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.extractToRight<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PE_CACHE_INJECT_CNTL_REG));
#endif
    return i_data.getBit<REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_PHB5_PMON_COUNTERS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_PHB5_PMON_COUNTERS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_PHB5_PMON_COUNTERS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_PHB5_PMON_COUNTERS;
#endif
    return fapi2::getScom(i_target, RSB_REGS_PHB5_PMON_COUNTERS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_PHB5_PMON_COUNTERS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_PHB5_PMON_COUNTERS));
#endif
    return fapi2::putScom(i_target, RSB_REGS_PHB5_PMON_COUNTERS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
