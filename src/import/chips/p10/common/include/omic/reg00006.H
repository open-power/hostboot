/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omic/reg00006.H $         */
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

#ifndef __OMIC_REG00006_H_
#define __OMIC_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_CNTL5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_CNTL5_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_CNTL5_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD,
           CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD,
           CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD,
           CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_CNTL5_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE16_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE16_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE16_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE16_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE16_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH1,
           CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH1,
           CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_THRESH1,
           CTL_REGS_RX_MODE16_PG_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1,
           CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH2,
           CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE16_PG_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE16_PG_THRESH2,
           CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE16_PG_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE16_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE16_PG_THRESH2,
           CTL_REGS_RX_MODE16_PG_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE16_PG_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_MODE3_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE3_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_MODE3_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_MODE3_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_MODE3_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_MODE3_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_MODE3_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_FILTER_DEPTH,
           CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_FILTER_DEPTH,
           CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_FILTER_DEPTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_FILTER_DEPTH,
           CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_FILTER_DEPTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_THRESH4,
           CTL_REGS_RX_MODE3_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_THRESH4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_THRESH4,
           CTL_REGS_RX_MODE3_PG_THRESH4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_THRESH4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_THRESH4,
           CTL_REGS_RX_MODE3_PG_THRESH4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_THRESH4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG,
           CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG,
           CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG,
           CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_DATA_SRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_DATA_SRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE3_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE3_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_DATA_SRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE3_PG_DATA_SRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE3_PG_DATA_SRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_DATA_SRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FORMAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_FORMAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE3_PG_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE3_PG_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_FORMAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE3_PG_FORMAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE3_PG_FORMAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_FORMAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.setBit<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return o_data.clearBit<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_MODE3_PG));
#endif
    return i_data.getBit<CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_RX_FIR1_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_FIR1_ERROR_INJECT_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_RX_FIR1_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_RX_FIR1_ERROR_INJECT_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_RX_FIR1_ERROR_INJECT_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_RX_FIR1_ERROR_INJECT_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_ERROR_INJECT_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_RX_FIR1_ERROR_INJECT_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_ERROR_INJECT_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ,
           CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_ERROR_INJECT_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ,
           CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_RX_FIR1_ERROR_INJECT_PG));
#endif
    return i_data.extractToRight<CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ,
           CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL4_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CTL_REGS_TX_CNTL4_PG;
#endif
    return fapi2::getScom(i_target, CTL_REGS_TX_CNTL4_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CTL_REGS_TX_CNTL4_PG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return fapi2::putScom(i_target, CTL_REGS_TX_CNTL4_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL4_PG_DAC_CNTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL4_PG_DAC_CNTL,
           CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL4_PG_DAC_CNTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.insertFromRight<CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.setBit<CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return o_data.clearBit<CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.extractToRight<CTL_REGS_TX_CNTL4_PG_PHASE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CTL_REGS_TX_CNTL4_PG_PHASE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CTL_REGS_TX_CNTL4_PG));
#endif
    return i_data.getBit<CTL_REGS_TX_CNTL4_PG_PHASE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CTL_REGS_TX_CNTL4_PG_PHASE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT14_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT14_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT14_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT14_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT14_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT14_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT14_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_0_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_0_SEL,
           DATASM_REGS_RX_CNT14_PG_0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT14_PG_0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_0_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_0_SEL,
           DATASM_REGS_RX_CNT14_PG_0_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT14_PG_0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT14_PG_0_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT14_PG_0_SEL,
           DATASM_REGS_RX_CNT14_PG_0_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT14_PG_0_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_1_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_1_SEL,
           DATASM_REGS_RX_CNT14_PG_1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT14_PG_1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_1_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_1_SEL,
           DATASM_REGS_RX_CNT14_PG_1_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT14_PG_1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT14_PG_1_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT14_PG_1_SEL,
           DATASM_REGS_RX_CNT14_PG_1_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT14_PG_1_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_2_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_2_SEL,
           DATASM_REGS_RX_CNT14_PG_2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT14_PG_2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT14_PG_2_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT14_PG_2_SEL,
           DATASM_REGS_RX_CNT14_PG_2_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT14_PG_2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT14_PG_2_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT14_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT14_PG_2_SEL,
           DATASM_REGS_RX_CNT14_PG_2_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT14_PG_2_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNT24_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT24_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNT24_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNT24_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNT24_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNT24_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT24_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNT24_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT24_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23,
           DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT24_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23,
           DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNT24_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23,
           DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_CNTL7_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_CNTL7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_CNTL7_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_CNTL7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
           DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return o_data.insertFromRight<DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
           DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_CNTL7_PG));
#endif
    return i_data.extractToRight<DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15,
           DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT19_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT19_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT19_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT19_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT19_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT19_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT19_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT19_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DATASM_REGS_RX_STAT7_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT7_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DATASM_REGS_RX_STAT7_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DATASM_REGS_RX_STAT7_PG;
#endif
    return fapi2::getScom(i_target, DATASM_REGS_RX_STAT7_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DATASM_REGS_RX_STAT7_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DATASM_REGS_RX_STAT7_PG));
#endif
    return fapi2::putScom(i_target, DATASM_REGS_RX_STAT7_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_CNTL5_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_CNTL5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_CNTL5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return o_data.insertFromRight<TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_CNTL5_PG));
#endif
    return i_data.extractToRight<TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15,
           TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT5_PG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TX_CTL_SM_REGS_CTLSM_STAT5_PG;
#endif
    return fapi2::getScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT5_PG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TX_CTL_SM_REGS_CTLSM_STAT5_PG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TX_CTL_SM_REGS_CTLSM_STAT5_PG));
#endif
    return fapi2::putScom(i_target, TX_CTL_SM_REGS_CTLSM_STAT5_PG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}



#ifndef __PPE_HCODE__
}
}

#endif
#endif
