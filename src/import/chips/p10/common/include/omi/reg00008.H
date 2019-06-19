/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00008.H $          */
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

#ifndef __OMI_REG00008_H_
#define __OMI_REG00008_H_

namespace scomt
{
namespace omi
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_13_PLREGS_RX_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_STAT1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_13_PLREGS_RX_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_5_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_5_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_5_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_5_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_FIR_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_NS_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL5_PL_EW_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_SIGDET_PD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL,
           RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
