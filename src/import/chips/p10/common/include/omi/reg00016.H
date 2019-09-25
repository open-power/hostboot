/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00016.H $          */
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

#ifndef __OMI_REG00016_H_
#define __OMI_REG00016_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_11_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_13_PLREGS_RX_MODE1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_13_PLREGS_RX_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_13_PLREGS_RX_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_13_PLREGS_RX_MODE1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_13_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_15_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_REQ_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_23_PLREGS_RX_CNTL3_PL_STS_ALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_INIT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_CNTL1_PL_RECAL_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_5_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_5_PLREGS_RX_STAT1_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_5_PLREGS_RX_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_5_PLREGS_RX_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_5_PLREGS_RX_STAT1_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_5_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL;
#endif
    return fapi2::getScom(i_target, RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return fapi2::putScom(i_target, RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.insertFromRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.setBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return o_data.clearBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.extractToRight<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL));
#endif
    return i_data.getBit<RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXCTL_DATASM_8_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL18_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO,
           RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_CNTL6_PL_R_PSAVE_VAL_ENA_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_STAT6_PL_RX_ERROR_VEC_16_31_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK,
           RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2,
           RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO,
           RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_MODE7_PL_SAVE_EN_DL_CLK_CONTROL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_BUMP_IN_PROGRESS_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_IN_COARSE_MODE_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_LOCKED_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_A_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PR_UNLOCKED_B_STICKY_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_BIT_REGS_STAT1_PL_SIGNAL_DETECT_OUT_RO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL,
           RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE,
           RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.setBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.clearBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.getBit<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL;
#endif
    return fapi2::getScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL));
#endif
    return fapi2::putScom(i_target, RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL));
#endif
    return o_data.insertFromRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL));
#endif
    return i_data.extractToRight<RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL,
           RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RXPACKS_0_DEFAULT_RD_5_RX_BIT_REGS_STAT3_PL_RX_PR_FW_SNAPSHOT_B_RO_SIGNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
