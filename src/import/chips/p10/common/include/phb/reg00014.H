/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00014.H $          */
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

#ifndef __PHB_REG00014_H_
#define __PHB_REG00014_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_INTBAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_INTBAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_INTBAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_INTBAR_REG;
#endif
    return fapi2::getScom(i_target, REGS_INTBAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_INTBAR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_INTBAR_REG));
#endif
    return fapi2::putScom(i_target, REGS_INTBAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_INTBAR_REG_PE_INT_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_INTBAR_REG));
#endif
    return o_data.insertFromRight<REGS_INTBAR_REG_PE_INT_BAR,
           REGS_INTBAR_REG_PE_INT_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_INTBAR_REG_PE_INT_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_INTBAR_REG_PE_INT_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_INTBAR_REG));
#endif
    return o_data.insertFromRight<REGS_INTBAR_REG_PE_INT_BAR,
           REGS_INTBAR_REG_PE_INT_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_INTBAR_REG_PE_INT_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_INTBAR_REG_PE_INT_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_INTBAR_REG));
#endif
    return i_data.extractToRight<REGS_INTBAR_REG_PE_INT_BAR,
           REGS_INTBAR_REG_PE_INT_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_INTBAR_REG_PE_INT_BAR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PHBRESET_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PHBRESET_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PHBRESET_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PHBRESET_REG;
#endif
    return fapi2::getScom(i_target, REGS_PHBRESET_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PHBRESET_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return fapi2::putScom(i_target, REGS_PHBRESET_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return o_data.insertFromRight<REGS_PHBRESET_REG_PE_ETU_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PHBRESET_REG_PE_ETU_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return o_data.insertFromRight<REGS_PHBRESET_REG_PE_ETU_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return o_data.setBit<REGS_PHBRESET_REG_PE_ETU_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return o_data.clearBit<REGS_PHBRESET_REG_PE_ETU_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return i_data.extractToRight<REGS_PHBRESET_REG_PE_ETU_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_REGS_PHBRESET_REG_PE_ETU_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PHBRESET_REG));
#endif
    return i_data.getBit<REGS_PHBRESET_REG_PE_ETU_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PHBRESET_REG_PE_ETU_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL;
#endif
    return fapi2::getScom(i_target, RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return fapi2::putScom(i_target, RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE,
           RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE,
           RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE,
           RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE,
           RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE,
           RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE,
           RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_SCOM_SSR_PHB5_UVIAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB5_UVIAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_SCOM_SSR_PHB5_UVIAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB5_UVIAR;
#endif
    return fapi2::getScom(i_target, RSB_SCOM_SSR_PHB5_UVIAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_SCOM_SSR_PHB5_UVIAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return fapi2::putScom(i_target, RSB_SCOM_SSR_PHB5_UVIAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB5_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
