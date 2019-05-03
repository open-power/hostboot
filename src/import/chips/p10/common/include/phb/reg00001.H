/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00001.H $          */
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

#ifndef __PHB_REG00001_H_
#define __PHB_REG00001_H_

namespace scomt
{
namespace phb
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REGS_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PBAIBTXCCR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REGS_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REGS_PBAIBTXCCR_REG;
#endif
    return fapi2::getScom(i_target, REGS_PBAIBTXCCR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REGS_PBAIBTXCCR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return fapi2::putScom(i_target, REGS_PBAIBTXCCR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_0_CCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_0_CCA,
           REGS_PBAIBTXCCR_REG_0_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_0_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_0_CCA,
           REGS_PBAIBTXCCR_REG_0_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_0_CCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_0_CCA,
           REGS_PBAIBTXCCR_REG_0_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_0_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_0_CCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_0_CCR,
           REGS_PBAIBTXCCR_REG_0_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_0_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_0_CCR,
           REGS_PBAIBTXCCR_REG_0_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_0_CCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_0_CCR,
           REGS_PBAIBTXCCR_REG_0_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_0_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_1_CCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_1_CCA,
           REGS_PBAIBTXCCR_REG_1_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_1_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_1_CCA,
           REGS_PBAIBTXCCR_REG_1_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_1_CCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_1_CCA,
           REGS_PBAIBTXCCR_REG_1_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_1_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_1_CCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_1_CCR,
           REGS_PBAIBTXCCR_REG_1_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_1_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_1_CCR,
           REGS_PBAIBTXCCR_REG_1_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_1_CCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_1_CCR,
           REGS_PBAIBTXCCR_REG_1_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_1_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_2_CCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_2_CCA,
           REGS_PBAIBTXCCR_REG_2_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_2_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_2_CCA,
           REGS_PBAIBTXCCR_REG_2_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_2_CCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_2_CCA,
           REGS_PBAIBTXCCR_REG_2_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_2_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_2_CCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_2_CCR,
           REGS_PBAIBTXCCR_REG_2_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_2_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_2_CCR,
           REGS_PBAIBTXCCR_REG_2_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_2_CCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_2_CCR,
           REGS_PBAIBTXCCR_REG_2_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_2_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_3_CCA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_3_CCA,
           REGS_PBAIBTXCCR_REG_3_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_3_CCA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_3_CCA,
           REGS_PBAIBTXCCR_REG_3_CCA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_3_CCA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_3_CCA,
           REGS_PBAIBTXCCR_REG_3_CCA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_3_CCA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_3_CCR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_3_CCR,
           REGS_PBAIBTXCCR_REG_3_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_REGS_PBAIBTXCCR_REG_3_CCR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return o_data.insertFromRight<REGS_PBAIBTXCCR_REG_3_CCR,
           REGS_PBAIBTXCCR_REG_3_CCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_REGS_PBAIBTXCCR_REG_3_CCR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REGS_PBAIBTXCCR_REG));
#endif
    return i_data.extractToRight<REGS_PBAIBTXCCR_REG_3_CCR,
           REGS_PBAIBTXCCR_REG_3_CCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access REGS_PBAIBTXCCR_REG_3_CCR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK;
#endif
    return fapi2::getScom(i_target, RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return fapi2::putScom(i_target, RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE,
           RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_SCOM_SSR_PHB4_UVIAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB4_UVIAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_SCOM_SSR_PHB4_UVIAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_SCOM_SSR_PHB4_UVIAR;
#endif
    return fapi2::getScom(i_target, RSB_SCOM_SSR_PHB4_UVIAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_SCOM_SSR_PHB4_UVIAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return fapi2::putScom(i_target, RSB_SCOM_SSR_PHB4_UVIAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.setBit<RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.clearBit<RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return i_data.getBit<RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return o_data.insertFromRight<RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_SCOM_SSR_PHB4_UVIAR));
#endif
    return i_data.extractToRight<RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE,
           RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
