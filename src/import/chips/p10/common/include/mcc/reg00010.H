/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mcc/reg00010.H $          */
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

#ifndef __MCC_REG00010_H_
#define __MCC_REG00010_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ATCL_CL_CLSCOM_MCERRINJ(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCERRINJ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ATCL_CL_CLSCOM_MCERRINJ(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ATCL_CL_CLSCOM_MCERRINJ;
#endif
    return fapi2::getScom(i_target, ATCL_CL_CLSCOM_MCERRINJ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ATCL_CL_CLSCOM_MCERRINJ(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return fapi2::putScom(i_target, ATCL_CL_CLSCOM_MCERRINJ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ,
           ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ,
           ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ,
           ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_WB_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6,
           ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6,
           ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6,
           ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_RESERVED3_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return o_data.insertFromRight<ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return o_data.setBit<ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return o_data.clearBit<ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return i_data.extractToRight<ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ATCL_CL_CLSCOM_MCERRINJ));
#endif
    return i_data.getBit<ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ATCL_CL_CLSCOM_MCERRINJ_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLERRRPT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLERRRPT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLERRRPT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLERRRPT;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLERRRPT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLERRRPT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLERRRPT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_UNDERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_OVERFLOW_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXVC3_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLXDCP0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC0_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLVC1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_TLDCP1_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CMD_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_FF_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_DSTL_SHAREDPOOL_TLXDCP0_COUNTER_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SHARED_TLXDCP0_MAX_ERROR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC0_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_TLXVC3_OVERUSE_HOLD_OUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_READ_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANA_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CMD_CHANB_WRITE_QUEUE_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_DATA_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANA_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_WRDATA_CHANB_QUEUE_META_PARITY_ERR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_CREDIT_RETURN_PARITY_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANA_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_CHANB_WRDATA_COUNTER_ASSUMPTION_ERROR_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_A_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.insertFromRight<DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.setBit<DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return o_data.clearBit<DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.extractToRight<DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLERRRPT));
#endif
    return i_data.getBit<DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLERRRPT_SUBCHANNEL_B_FAIL_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRACT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRACT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRACT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRACT1;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRACT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRACT1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT1));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRACT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT1));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1,
           DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT1));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1,
           DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRACT1));
#endif
    return i_data.extractToRight<DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1,
           DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRACT1_DSTLFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLFIRWOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRWOF;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLFIRWOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLFIRWOF;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLFIRWOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLFIRWOF(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRWOF));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLFIRWOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRWOF));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF,
           DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRWOF));
#endif
    return o_data.insertFromRight<DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF,
           DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLFIRWOF));
#endif
    return i_data.extractToRight<DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF,
           DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLFIRWOF_DSTLFIRWOF_WOF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DSTL_DSTLPSAVE0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLPSAVE0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DSTL_DSTLPSAVE0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DSTL_DSTLPSAVE0;
#endif
    return fapi2::getScom(i_target, DSTL_DSTLPSAVE0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DSTL_DSTLPSAVE0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return fapi2::putScom(i_target, DSTL_DSTLPSAVE0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_MIN_RAND_UCNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_MIN_RAND_UCNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL,
           DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_MASTER_PSAVE_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL,
           DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_SLAVE_PSAVE_EVENT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.setBit<DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.clearBit<DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.getBit<DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE,
           DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE,
           DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE,
           DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_PSAVE_REQUEST_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_RESERVED_43_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_RESERVED_43_47,
           DSTL_DSTLPSAVE0_RESERVED_43_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_RESERVED_43_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DSTL_DSTLPSAVE0_RESERVED_43_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return o_data.insertFromRight<DSTL_DSTLPSAVE0_RESERVED_43_47,
           DSTL_DSTLPSAVE0_RESERVED_43_47_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_RESERVED_43_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DSTL_DSTLPSAVE0_RESERVED_43_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DSTL_DSTLPSAVE0));
#endif
    return i_data.extractToRight<DSTL_DSTLPSAVE0_RESERVED_43_47,
           DSTL_DSTLPSAVE0_RESERVED_43_47_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DSTL_DSTLPSAVE0_RESERVED_43_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
