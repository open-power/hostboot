/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00020.H $          */
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

#ifndef __OMI_REG00020_H_
#define __OMI_REG00020_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ERROR_CAPTURE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_CAPTURE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ERROR_CAPTURE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_CAPTURE;
#endif
    return fapi2::getScom(i_target, ERROR_CAPTURE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ERROR_CAPTURE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ERROR_CAPTURE));
#endif
    return fapi2::putScom(i_target, ERROR_CAPTURE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_CAPTURE));
#endif
    return o_data.insertFromRight<ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO,
           ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_CAPTURE));
#endif
    return o_data.insertFromRight<ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO,
           ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_CAPTURE));
#endif
    return i_data.extractToRight<ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO,
           ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_CAPTURE));
#endif
    return o_data.insertFromRight<ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO,
           ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_CAPTURE));
#endif
    return o_data.insertFromRight<ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO,
           ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_CAPTURE));
#endif
    return i_data.extractToRight<ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO,
           ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_11_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_11_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_11_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_11_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_7_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_7_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_7_PLREGS_RX_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_7_PLREGS_RX_STAT1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_7_PLREGS_RX_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_8_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_8_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_8_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_8_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL3_PL_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL4_PL_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE2_PL_LOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT4_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT4_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT4_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT4_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT4_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT4_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT4_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT4_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT6_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return o_data.insertFromRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL));
#endif
    return i_data.extractToRight<RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100,
           RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
