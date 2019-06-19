/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00010.H $         */
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

#ifndef __OMIC_REG00010_H_
#define __OMIC_REG00010_H_

namespace scomt
{
namespace omic
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_CNTL3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_CNTL3_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_CNTL3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_CNTL3_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_CNTL3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL3_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL3_PG_FIR_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL3_PG_FIR_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL3_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL3_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL3_PG_FIR_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL3_PG_FIR_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL3_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL3_PG_FIR_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL3_PG_FIR_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE10_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE10_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE10_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE10_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE10_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE10_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_FILTER_DEPTH,
           CTL_REGS_RX_MODE10_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_FILTER_DEPTH,
           CTL_REGS_RX_MODE10_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE10_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE10_PG_FILTER_DEPTH,
           CTL_REGS_RX_MODE10_PG_FILTER_DEPTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_THRESH4,
           CTL_REGS_RX_MODE10_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_THRESH4,
           CTL_REGS_RX_MODE10_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE10_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE10_PG_THRESH4,
           CTL_REGS_RX_MODE10_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG,
           CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG,
           CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG,
           CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_DATA_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE10_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE10_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE10_PG_DATA_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE10_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE10_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE10_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE20_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE20_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE20_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE20_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE20_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE20_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE20_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE20_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE20_PG_AMP_HYST_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE20_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE20_PG_AMP_HYST_START,
           CTL_REGS_RX_MODE20_PG_AMP_HYST_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE20_PG_AMP_HYST_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE20_PG_AMP_HYST_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE20_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE20_PG_AMP_HYST_START,
           CTL_REGS_RX_MODE20_PG_AMP_HYST_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE20_PG_AMP_HYST_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE20_PG_AMP_HYST_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE20_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE20_PG_AMP_HYST_START,
           CTL_REGS_RX_MODE20_PG_AMP_HYST_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE20_PG_AMP_HYST_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE20_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE20_PG_LOFF_HYST_START,
           CTL_REGS_RX_MODE20_PG_LOFF_HYST_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE20_PG_LOFF_HYST_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE20_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE20_PG_LOFF_HYST_START,
           CTL_REGS_RX_MODE20_PG_LOFF_HYST_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE20_PG_LOFF_HYST_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE20_PG_LOFF_HYST_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE20_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE20_PG_LOFF_HYST_START,
           CTL_REGS_RX_MODE20_PG_LOFF_HYST_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE20_PG_LOFF_HYST_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE5_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE5_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE5_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE5_PG_THRESH1,
           CTL_REGS_RX_MODE5_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE5_PG_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE5_PG_THRESH1,
           CTL_REGS_RX_MODE5_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE5_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE5_PG_THRESH1,
           CTL_REGS_RX_MODE5_PG_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE5_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE5_PG_THRESH2,
           CTL_REGS_RX_MODE5_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE5_PG_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE5_PG_THRESH2,
           CTL_REGS_RX_MODE5_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE5_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE5_PG_THRESH2,
           CTL_REGS_RX_MODE5_PG_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE5_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_FIR1_MASK_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_FIR1_MASK_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_FIR1_MASK_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_FIR1_MASK_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_FIR1_MASK_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_FIR1_MASK_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_MASK_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_FIR1_MASK_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_MASK_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK,
           CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_MASK_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK,
           CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_MASK_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK,
           CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL10_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL10_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL10_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL10_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL10_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL10_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL10_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL10_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63,
           CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL10_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63,
           CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL10_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63,
           CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL2_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL2_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL2_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL2_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL2_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_A_FINE_SEL,
           CTL_REGS_TX_CNTL2_PG_A_FINE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_A_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_A_FINE_SEL,
           CTL_REGS_TX_CNTL2_PG_A_FINE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_A_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL2_PG_A_FINE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL2_PG_A_FINE_SEL,
           CTL_REGS_TX_CNTL2_PG_A_FINE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_A_FINE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL,
           CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL,
           CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL,
           CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_A_BER_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_A_BER_SEL,
           CTL_REGS_TX_CNTL2_PG_A_BER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_A_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_A_BER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_A_BER_SEL,
           CTL_REGS_TX_CNTL2_PG_A_BER_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_A_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL2_PG_A_BER_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL2_PG_A_BER_SEL,
           CTL_REGS_TX_CNTL2_PG_A_BER_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_A_BER_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_CNTL2_PG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_CNTL2_PG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL2_PG_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_TX_CNTL2_PG_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_CNTL2_PG_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL2_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT12_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT12_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT12_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT12_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT12_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT12_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT12_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT12_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT12_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23,
           DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT12_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23,
           DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT12_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23,
           DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT22_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT22_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT22_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT22_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT22_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT22_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT22_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.setBit<DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return o_data.clearBit<DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT22_PG));
#endif
    return i_data.getBit<DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT32_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT32_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT32_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT32_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT32_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT32_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT32_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT32_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT32_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1,
           DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT32_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1,
           DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT32_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1,
           DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL1_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL1_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL1_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT1_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT1_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT1_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT1_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT1_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT1_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT1_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT1_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL13_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL13_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL13_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL13_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL13_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL13_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL13_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL13_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL13_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1,
           TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL13_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1,
           TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL13_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1,
           TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL3_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL3_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL3_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL3_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL3_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL3_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_STAT3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_STAT3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT3_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_STAT3_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT3_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



}
}

#endif
