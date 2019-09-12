/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00031.H $         */
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

#ifndef __PERV_REG00031_H_
#define __PERV_REG00031_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG65(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG65;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG65(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG65;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG65, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG65(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG65));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG65, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG65));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65,
           SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG65));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65,
           SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG65));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65,
           SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG65_REGISTER65 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG90(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG90;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG90(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG90;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG90, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG90(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG90));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG90, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG90));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90,
           SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG90));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90,
           SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG90));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90,
           SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access SINGLE_OTP_ROM_OTPROM_REG90_REGISTER90 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TIMEOUT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TIMEOUT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TIMEOUT_REG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TIMEOUT_REG;
#endif
    return fapi2::getScom(i_target, TIMEOUT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TIMEOUT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TIMEOUT_REG));
#endif
    return fapi2::putScom(i_target, TIMEOUT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TIMEOUT_REG_INT_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TIMEOUT_REG));
#endif
    return o_data.insertFromRight<TIMEOUT_REG_INT_TIMEOUT,
           TIMEOUT_REG_INT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TIMEOUT_REG_INT_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TIMEOUT_REG));
#endif
    return o_data.insertFromRight<TIMEOUT_REG_INT_TIMEOUT,
           TIMEOUT_REG_INT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TIMEOUT_REG_INT_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TIMEOUT_REG));
#endif
    return i_data.extractToRight<TIMEOUT_REG_INT_TIMEOUT,
           TIMEOUT_REG_INT_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_ERROR_INJECT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_ERROR_INJECT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_ERROR_INJECT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_ERROR_INJECT_REG;
#endif
    return fapi2::getScom(i_target, TOD_ERROR_INJECT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_ERROR_INJECT_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return fapi2::putScom(i_target, TOD_ERROR_INJECT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X00_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X01_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X02_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X03_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X04_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X05_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X06_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X07_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X08_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X09_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0A_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_M_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_0_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PSS_HAM_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PSS_HAM_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PSS_HAM_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PSS_HAM_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PSS_HAM_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PSS_HAM_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PSS_HAM_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_PSS_HAM_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PSS_HAM_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_PSS_HAM_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_PSS_HAM_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PSS_HAM_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_PSS_HAM_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_PSS_HAM_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PSS_HAM_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_PSS_HAM_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_PSS_HAM_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PSS_HAM_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0B_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_S_PATH_1_STEP_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X0C_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X20_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X23_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X24_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X29_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X10_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_SYNC_CHECK_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_FSM_STATE_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_I_PATH_TIME_REG_OVERFLOW_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_INJECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_0_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_1_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_2_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_3_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_5_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_WRITE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_READ_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_ADDR_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_SLAVE_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_REG_0X27_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT,
           TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT,
           TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT,
           TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_MASTER_RSP_INFO_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_INVALID_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_RX_TTYPE_4_DATA_PARITY_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_MASTER_REQUEST_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_PIB_RESET_DURING_ACCESS_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_EXTERNAL_XSTOP_ERROR_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_SPARE_ERROR_INJECT_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_OSCSWITCH_INTERRUPT_INJECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.setBit<TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return o_data.clearBit<TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_INJECT_REG));
#endif
    return i_data.getBit<TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TOD_ERROR_INJECT_REG_CORE_STEP_ERROR_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA0_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_CONFIG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA0_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_CONFIG_1;
#endif
    return fapi2::getScom(i_target, TRA0_TR0_CONFIG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA0_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_1));
#endif
    return fapi2::putScom(i_target, TRA0_TR0_CONFIG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_1));
#endif
    return i_data.extractToRight<TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA2_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR0_CONFIG_9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA2_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR0_CONFIG_9;
#endif
    return fapi2::getScom(i_target, TRA2_TR0_CONFIG_9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA2_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return fapi2::putScom(i_target, TRA2_TR0_CONFIG_9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCHA_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCHA_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCHA_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_MATCHA_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCHB_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCHB_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCHB_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_MATCHB_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCHC_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCHC_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCHC_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_MATCHC_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCHD_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCHD_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCHD_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_MATCHD_MUXSEL,
           TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG0_OR_MASK,
           TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG0_OR_MASK,
           TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_TRIG0_OR_MASK,
           TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG0_AND_MASK,
           TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG0_AND_MASK,
           TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_TRIG0_AND_MASK,
           TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG1_OR_MASK,
           TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG1_OR_MASK,
           TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_TRIG1_OR_MASK,
           TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG1_AND_MASK,
           TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG1_AND_MASK,
           TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_TRIG1_AND_MASK,
           TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCH_NOT_MODE,
           TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_MATCH_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_MATCH_NOT_MODE,
           TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_MATCH_NOT_MODE,
           TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_ERROR_CMP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_SPARE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<TRA2_TR0_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.setBit<TRA2_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA2_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return o_data.clearBit<TRA2_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<TRA2_TR0_CONFIG_9_SPARE_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA2_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR0_CONFIG_9));
#endif
    return i_data.getBit<TRA2_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA2_TR1_CONFIG_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR1_CONFIG_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA2_TR1_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR1_CONFIG_0;
#endif
    return fapi2::getScom(i_target, TRA2_TR1_CONFIG_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA2_TR1_CONFIG_0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_0));
#endif
    return fapi2::putScom(i_target, TRA2_TR1_CONFIG_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_0));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_0));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_0));
#endif
    return i_data.extractToRight<TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA4_TR1_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR1_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA4_TR1_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR1_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, TRA4_TR1_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA4_TR1_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, TRA4_TR1_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA,
           TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA,
           TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA,
           TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS,
           TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS,
           TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS,
           TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK,
           TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK,
           TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK,
           TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA4_TR1_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TRA4_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA4_TR1_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA4_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR1_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TRA4_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA4_TR1_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA4_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA5_TR1_CONFIG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA5_TR1_CONFIG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA5_TR1_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA5_TR1_CONFIG_1;
#endif
    return fapi2::getScom(i_target, TRA5_TR1_CONFIG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA5_TR1_CONFIG_1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_1));
#endif
    return fapi2::putScom(i_target, TRA5_TR1_CONFIG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_1));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_1));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_1));
#endif
    return i_data.extractToRight<TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA5_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA7_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA7_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, TRA7_TR0_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA7_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA7_TR0_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, TRA7_TR0_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA7_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA7_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG_0;
#endif
    return fapi2::getScom(i_target, TRA7_TR0_CONFIG_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA7_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_0));
#endif
    return fapi2::putScom(i_target, TRA7_TR0_CONFIG_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_0));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TRA7_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VITAL_SCAN_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = VITAL_SCAN_OUT;
#endif
    return fapi2::getScom(i_target, VITAL_SCAN_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(VITAL_SCAN_OUT));
#endif
    return fapi2::putScom(i_target, VITAL_SCAN_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_UNMASKED(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_UNMASKED;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_UNMASKED(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_UNMASKED;
#endif
    return fapi2::getScom(i_target, XSTOP_UNMASKED, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_UNMASKED(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_UNMASKED));
#endif
    return fapi2::putScom(i_target, XSTOP_UNMASKED, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSTOP_UNMASKED_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_UNMASKED));
#endif
    return o_data.insertFromRight<XSTOP_UNMASKED_IN,
           XSTOP_UNMASKED_IN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_UNMASKED_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSTOP_UNMASKED_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_UNMASKED));
#endif
    return o_data.insertFromRight<XSTOP_UNMASKED_IN,
           XSTOP_UNMASKED_IN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_UNMASKED_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSTOP_UNMASKED_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_UNMASKED));
#endif
    return i_data.extractToRight<XSTOP_UNMASKED_IN,
           XSTOP_UNMASKED_IN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSTOP_UNMASKED_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
