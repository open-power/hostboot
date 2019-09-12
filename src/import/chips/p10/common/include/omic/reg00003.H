/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00003.H $         */
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

#ifndef __OMIC_REG00003_H_
#define __OMIC_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE17_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE17_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE17_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE17_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE17_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_THRESH3,
           CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_THRESH3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_THRESH3,
           CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE17_PG_THRESH3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE17_PG_THRESH3,
           CTL_REGS_RX_MODE17_PG_THRESH3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3,
           CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_THRESH4,
           CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE17_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE17_PG_THRESH4,
           CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE17_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE17_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE17_PG_THRESH4,
           CTL_REGS_RX_MODE17_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE17_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE2_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE2_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE2_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT,
           CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT,
           CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT,
           CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK,
           CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK,
           CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK,
           CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE2_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL5_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL5_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET,
           CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET,
           CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET,
           CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT15_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT15_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT15_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT15_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT15_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT15_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT15_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT15_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT15_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL,
           DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT15_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL,
           DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT15_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL,
           DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT25_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT25_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT25_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT25_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT25_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT25_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT25_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT25_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT25_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15,
           DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT25_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15,
           DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT25_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15,
           DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL6_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL6_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL6_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL6_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL6_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
           DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL6_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
           DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL6_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
           DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT18_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT18_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT18_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT18_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT18_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT18_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT18_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT18_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT18_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL,
           DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT18_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL,
           DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT18_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL,
           DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_STAT18_PG_RX_LOFF_HYST_MIN_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT28_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT28_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT28_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT28_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT28_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT28_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT28_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT28_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT28_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL,
           DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT28_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL,
           DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT28_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL,
           DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_STAT28_PG_RX_QPA_VOTE_DIFF_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT6_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT6_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT6_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT6_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT6_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT6_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT6_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT6_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT6_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL,
           DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT6_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL,
           DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT6_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL,
           DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_STAT6_PG_RX_SERVO_STATUS0_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_MC_OMI_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_MC_OMI_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = MC_OMI_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, MC_OMI_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_MC_OMI_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, MC_OMI_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK,
           MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(MC_OMI_FIR_MASK_REG_RW, MC_OMI_FIR_MASK_REG_WO_AND, MC_OMI_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL14_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL14_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL14_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL14_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL14_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL14_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL14_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL14_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1,
           TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL14_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1,
           TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL14_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1,
           TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL4_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL4_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL4_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL4_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23,
           TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL4_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23,
           TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL4_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23,
           TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_STAT4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT4_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_STAT4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT4_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_STAT4_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT4_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT4_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL,
           TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT4_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL,
           TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT4_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL,
           TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_STAT4_PG_TX_PSAVE_STS_PHY_0_15_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
