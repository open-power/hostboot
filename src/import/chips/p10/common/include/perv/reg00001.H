/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00001.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __PERV_REG00001_H_
#define __PERV_REG00001_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RESET_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RESET_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RESET_REG]

//>> GET_[RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RESET_REG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RESET_REG;
#endif
    return fapi2::getScom(i_target, RESET_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RESET_REG]

//>> PUT_[RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RESET_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return fapi2::putScom(i_target, RESET_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RESET_REG]


//>> SET_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_RESET_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_PCB]

//>> SET_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_PCB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_RESET_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_PCB]

//>> SET_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.setBit<RESET_REG_RESET_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_PCB]

//>> CLEAR_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& CLEAR_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.clearBit<RESET_REG_RESET_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RESET_REG_RESET_PCB]

//>> GET_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& GET_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.extractToRight<RESET_REG_RESET_PCB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_RESET_PCB]

//>> GET_[RESET_REG_RESET_PCB]
static inline bool GET_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.getBit<RESET_REG_RESET_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_RESET_PCB]

//>> SET_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_RESET_ENDPOINTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_ENDPOINTS]

//>> SET_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_ENDPOINTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_RESET_ENDPOINTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_ENDPOINTS]

//>> SET_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.setBit<RESET_REG_RESET_ENDPOINTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_ENDPOINTS]

//>> CLEAR_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& CLEAR_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.clearBit<RESET_REG_RESET_ENDPOINTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RESET_REG_RESET_ENDPOINTS]

//>> GET_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& GET_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.extractToRight<RESET_REG_RESET_ENDPOINTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_RESET_ENDPOINTS]

//>> GET_[RESET_REG_RESET_ENDPOINTS]
static inline bool GET_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.getBit<RESET_REG_RESET_ENDPOINTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_RESET_ENDPOINTS]

//>> SET_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_TIMEOUT_RESET_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_TIMEOUT_RESET_EN]

//>> SET_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_TIMEOUT_RESET_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_TIMEOUT_RESET_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_TIMEOUT_RESET_EN]

//>> SET_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.setBit<RESET_REG_TIMEOUT_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_TIMEOUT_RESET_EN]

//>> CLEAR_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.clearBit<RESET_REG_TIMEOUT_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RESET_REG_TIMEOUT_RESET_EN]

//>> GET_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& GET_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.extractToRight<RESET_REG_TIMEOUT_RESET_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_TIMEOUT_RESET_EN]

//>> GET_[RESET_REG_TIMEOUT_RESET_EN]
static inline bool GET_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.getBit<RESET_REG_TIMEOUT_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_TIMEOUT_RESET_EN]

//>> PREP_[SCAN_CAPTUREDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN_CAPTUREDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN_CAPTUREDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN_CAPTUREDR]

//>> GET_[SCAN_CAPTUREDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN_CAPTUREDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN_CAPTUREDR;
#endif
    return fapi2::getScom(i_target, SCAN_CAPTUREDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN_CAPTUREDR]

//>> PUT_[SCAN_CAPTUREDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN_CAPTUREDR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN_CAPTUREDR));
#endif
    return fapi2::putScom(i_target, SCAN_CAPTUREDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN_CAPTUREDR]


//>> SET_[SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_CAPTUREDR));
#endif
    return o_data.insertFromRight<SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG,
           SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG]

//>> SET_[SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_CAPTUREDR));
#endif
    return o_data.insertFromRight<SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG,
           SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG]

//>> GET_[SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG]
static inline fapi2::buffer<uint64_t>& GET_SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_CAPTUREDR));
#endif
    return i_data.extractToRight<SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG,
           SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_CAPTUREDR_SCAN_CAPTUREDR_REG]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG110]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG110(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG110;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG110]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG110]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG110(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG110;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG110, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG110]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG110]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG110(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG110));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG110, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG110]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG110));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110,
           SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG110));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110,
           SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG110));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110,
           SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG110_REGISTER110]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG127]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG127(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG127;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG127]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG127]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG127(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG127;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG127, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG127]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG127]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG127(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG127));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG127, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG127]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG127));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127,
           SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG127));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127,
           SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG127));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127,
           SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG127_REGISTER127]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG29]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG29(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG29;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG29]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG29]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG29(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG29;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG29, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG29]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG29]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG29(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG29));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG29, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG29]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG29));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29,
           SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG29));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29,
           SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG29));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29,
           SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG29_REGISTER29]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG36]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG36(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG36;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG36]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG36]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG36(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG36;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG36, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG36]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG36]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG36(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG36));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG36, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG36]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG36));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36,
           SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG36));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36,
           SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG36));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36,
           SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG36_REGISTER36]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG48]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG48(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG48;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG48]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG48]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG48(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG48;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG48, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG48]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG48]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG48(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG48));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG48, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG48]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG48));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48,
           SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG48));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48,
           SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG48));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48,
           SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG48_REGISTER48]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG57]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG57(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG57;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG57]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG57]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG57(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG57;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG57, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG57]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG57]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG57(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG57));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG57, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG57]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG57));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57,
           SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG57));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57,
           SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG57));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57,
           SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG57_REGISTER57]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG60]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG60(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG60;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG60]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG60]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG60(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG60;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG60, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG60]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG60]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG60(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG60));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG60, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG60]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG60));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60,
           SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG60));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60,
           SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG60));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60,
           SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG60_REGISTER60]

//>> PREP_[SINGLE_OTP_ROM_OTPROM_REG95]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SINGLE_OTP_ROM_OTPROM_REG95(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG95;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SINGLE_OTP_ROM_OTPROM_REG95]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG95]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SINGLE_OTP_ROM_OTPROM_REG95(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SINGLE_OTP_ROM_OTPROM_REG95;
#endif
    return fapi2::getScom(i_target, SINGLE_OTP_ROM_OTPROM_REG95, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG95]

//>> PUT_[SINGLE_OTP_ROM_OTPROM_REG95]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SINGLE_OTP_ROM_OTPROM_REG95(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG95));
#endif
    return fapi2::putScom(i_target, SINGLE_OTP_ROM_OTPROM_REG95, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SINGLE_OTP_ROM_OTPROM_REG95]


//>> SET_[SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG95));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95,
           SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95]

//>> SET_[SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95]
static inline fapi2::buffer<uint64_t>& SET_SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG95));
#endif
    return o_data.insertFromRight<SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95,
           SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95]

//>> GET_[SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95]
static inline fapi2::buffer<uint64_t>& GET_SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SINGLE_OTP_ROM_OTPROM_REG95));
#endif
    return i_data.extractToRight<SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95,
           SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SINGLE_OTP_ROM_OTPROM_REG95_REGISTER95]

//>> PREP_[TOD_MISC_RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_MISC_RESET_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_MISC_RESET_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_MISC_RESET_REG]

//>> GET_[TOD_MISC_RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_MISC_RESET_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_MISC_RESET_REG;
#endif
    return fapi2::getScom(i_target, TOD_MISC_RESET_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_MISC_RESET_REG]

//>> PUT_[TOD_MISC_RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_MISC_RESET_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return fapi2::putScom(i_target, TOD_MISC_RESET_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_MISC_RESET_REG]


//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]

//>> GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline bool GET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline bool GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> CLEAR_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline bool GET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline bool GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> CLEAR_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline bool GET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> SET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_DATA_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_TRACE_DATA_SELECT,
           TOD_MISC_RESET_REG_TRACE_DATA_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_DATA_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]

//>> SET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_DATA_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_TRACE_DATA_SELECT,
           TOD_MISC_RESET_REG_TRACE_DATA_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_DATA_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]

//>> GET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_TRACE_DATA_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_TRACE_DATA_SELECT,
           TOD_MISC_RESET_REG_TRACE_DATA_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_DATA_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> CLEAR_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline bool GET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> CLEAR_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline bool GET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE,
           TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE,
           TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE,
           TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]

//>> GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]

//>> PREP_[TOD_SEC_PORT_0_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_SEC_PORT_0_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_SEC_PORT_0_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_SEC_PORT_0_CTRL_REG]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_SEC_PORT_0_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_SEC_PORT_0_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_SEC_PORT_0_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG]

//>> PUT_[TOD_SEC_PORT_0_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_SEC_PORT_0_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_SEC_PORT_0_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_SEC_PORT_0_CTRL_REG]


//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31,
           TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31,
           TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31,
           TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE,
           TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE,
           TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE,
           TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]

//>> PREP_[TRA0_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA0_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA0_TR0_CONFIG_4]

//>> GET_[TRA0_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA0_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TRA0_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA0_TR0_CONFIG_4]

//>> PUT_[TRA0_TR0_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA0_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TRA0_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA0_TR0_CONFIG_4]


//>> SET_[TRA0_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA0_TR0_CONFIG_4_A,
           TRA0_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_CONFIG_4_A]

//>> SET_[TRA0_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA0_TR0_CONFIG_4_A,
           TRA0_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_CONFIG_4_A]

//>> GET_[TRA0_TR0_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TRA0_TR0_CONFIG_4_A,
           TRA0_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_CONFIG_4_A]

//>> SET_[TRA0_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA0_TR0_CONFIG_4_B,
           TRA0_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_CONFIG_4_B]

//>> SET_[TRA0_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA0_TR0_CONFIG_4_B,
           TRA0_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_CONFIG_4_B]

//>> GET_[TRA0_TR0_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TRA0_TR0_CONFIG_4_B,
           TRA0_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_CONFIG_4_B]

//>> PREP_[TRA1_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA1_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA1_TR0_TRACE_LO_DATA_REG]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA1_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, TRA1_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG]

//>> PUT_[TRA1_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA1_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, TRA1_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA1_TR0_TRACE_LO_DATA_REG]


//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> CLEAR_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline bool GET_TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> CLEAR_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline bool GET_TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA1_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> CLEAR_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA1_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA1_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA1_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline bool GET_TRA1_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA1_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> SET_[TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> GET_[TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> PREP_[TRA1_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA1_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR1_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA1_TR1_CONFIG_2]

//>> GET_[TRA1_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA1_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA1_TR1_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TRA1_TR1_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA1_TR1_CONFIG_2]

//>> PUT_[TRA1_TR1_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA1_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA1_TR1_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TRA1_TR1_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA1_TR1_CONFIG_2]


//>> SET_[TRA1_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA1_TR1_CONFIG_2_A,
           TRA1_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR1_CONFIG_2_A]

//>> SET_[TRA1_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR1_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA1_TR1_CONFIG_2_A,
           TRA1_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR1_CONFIG_2_A]

//>> GET_[TRA1_TR1_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TRA1_TR1_CONFIG_2_A,
           TRA1_TR1_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR1_CONFIG_2_A]

//>> SET_[TRA1_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA1_TR1_CONFIG_2_B,
           TRA1_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA1_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR1_CONFIG_2_B]

//>> SET_[TRA1_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_TRA1_TR1_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA1_TR1_CONFIG_2_B,
           TRA1_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA1_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA1_TR1_CONFIG_2_B]

//>> GET_[TRA1_TR1_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& GET_TRA1_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA1_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TRA1_TR1_CONFIG_2_B,
           TRA1_TR1_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA1_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA1_TR1_CONFIG_2_B]

//>> PREP_[TRA2_TR1_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA2_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR1_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA2_TR1_TRACE_HI_DATA_REG]

//>> GET_[TRA2_TR1_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA2_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR1_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, TRA2_TR1_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA2_TR1_TRACE_HI_DATA_REG]

//>> PUT_[TRA2_TR1_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA2_TR1_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA2_TR1_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, TRA2_TR1_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA2_TR1_TRACE_HI_DATA_REG]


//>> SET_[TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> SET_[TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> GET_[TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& GET_TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> PREP_[TRA2_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA2_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR1_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA2_TR1_CONFIG_5]

//>> GET_[TRA2_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA2_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA2_TR1_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TRA2_TR1_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA2_TR1_CONFIG_5]

//>> PUT_[TRA2_TR1_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA2_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TRA2_TR1_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA2_TR1_CONFIG_5]


//>> SET_[TRA2_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_5_C,
           TRA2_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA2_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR1_CONFIG_5_C]

//>> SET_[TRA2_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_5_C,
           TRA2_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA2_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR1_CONFIG_5_C]

//>> GET_[TRA2_TR1_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& GET_TRA2_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<TRA2_TR1_CONFIG_5_C,
           TRA2_TR1_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA2_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA2_TR1_CONFIG_5_C]

//>> SET_[TRA2_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_5_D,
           TRA2_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA2_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR1_CONFIG_5_D]

//>> SET_[TRA2_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_TRA2_TR1_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA2_TR1_CONFIG_5_D,
           TRA2_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA2_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA2_TR1_CONFIG_5_D]

//>> GET_[TRA2_TR1_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& GET_TRA2_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA2_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<TRA2_TR1_CONFIG_5_D,
           TRA2_TR1_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA2_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA2_TR1_CONFIG_5_D]

//>> PREP_[TRA3_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA3_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA3_TR0_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA3_TR0_CONFIG_3]

//>> GET_[TRA3_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA3_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA3_TR0_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TRA3_TR0_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA3_TR0_CONFIG_3]

//>> PUT_[TRA3_TR0_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA3_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TRA3_TR0_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA3_TR0_CONFIG_3]


//>> SET_[TRA3_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_TRA3_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA3_TR0_CONFIG_3_C,
           TRA3_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA3_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA3_TR0_CONFIG_3_C]

//>> SET_[TRA3_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_TRA3_TR0_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA3_TR0_CONFIG_3_C,
           TRA3_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA3_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA3_TR0_CONFIG_3_C]

//>> GET_[TRA3_TR0_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& GET_TRA3_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TRA3_TR0_CONFIG_3_C,
           TRA3_TR0_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA3_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA3_TR0_CONFIG_3_C]

//>> SET_[TRA3_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_TRA3_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA3_TR0_CONFIG_3_D,
           TRA3_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA3_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA3_TR0_CONFIG_3_D]

//>> SET_[TRA3_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_TRA3_TR0_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA3_TR0_CONFIG_3_D,
           TRA3_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA3_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA3_TR0_CONFIG_3_D]

//>> GET_[TRA3_TR0_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& GET_TRA3_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA3_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TRA3_TR0_CONFIG_3_D,
           TRA3_TR0_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA3_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA3_TR0_CONFIG_3_D]

//>> PREP_[TRA4_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA4_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR0_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA4_TR0_CONFIG_2]

//>> GET_[TRA4_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA4_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA4_TR0_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TRA4_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA4_TR0_CONFIG_2]

//>> PUT_[TRA4_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA4_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TRA4_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA4_TR0_CONFIG_2]


//>> SET_[TRA4_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA4_TR0_CONFIG_2_A,
           TRA4_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_CONFIG_2_A]

//>> SET_[TRA4_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA4_TR0_CONFIG_2_A,
           TRA4_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_CONFIG_2_A]

//>> GET_[TRA4_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TRA4_TR0_CONFIG_2_A,
           TRA4_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_CONFIG_2_A]

//>> SET_[TRA4_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA4_TR0_CONFIG_2_B,
           TRA4_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA4_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_CONFIG_2_B]

//>> SET_[TRA4_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_TRA4_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TRA4_TR0_CONFIG_2_B,
           TRA4_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA4_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA4_TR0_CONFIG_2_B]

//>> GET_[TRA4_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& GET_TRA4_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA4_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TRA4_TR0_CONFIG_2_B,
           TRA4_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA4_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA4_TR0_CONFIG_2_B]

//>> PREP_[TRA5_TR1_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA5_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA5_TR1_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA5_TR1_CONFIG_4]

//>> GET_[TRA5_TR1_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA5_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA5_TR1_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TRA5_TR1_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA5_TR1_CONFIG_4]

//>> PUT_[TRA5_TR1_CONFIG_4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA5_TR1_CONFIG_4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TRA5_TR1_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA5_TR1_CONFIG_4]


//>> SET_[TRA5_TR1_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_4_A,
           TRA5_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA5_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA5_TR1_CONFIG_4_A]

//>> SET_[TRA5_TR1_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_4_A,
           TRA5_TR1_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA5_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA5_TR1_CONFIG_4_A]

//>> GET_[TRA5_TR1_CONFIG_4_A]
static inline fapi2::buffer<uint64_t>& GET_TRA5_TR1_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TRA5_TR1_CONFIG_4_A,
           TRA5_TR1_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA5_TR1_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA5_TR1_CONFIG_4_A]

//>> SET_[TRA5_TR1_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_4_B,
           TRA5_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA5_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA5_TR1_CONFIG_4_B]

//>> SET_[TRA5_TR1_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& SET_TRA5_TR1_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return o_data.insertFromRight<TRA5_TR1_CONFIG_4_B,
           TRA5_TR1_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA5_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA5_TR1_CONFIG_4_B]

//>> GET_[TRA5_TR1_CONFIG_4_B]
static inline fapi2::buffer<uint64_t>& GET_TRA5_TR1_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA5_TR1_CONFIG_4));
#endif
    return i_data.extractToRight<TRA5_TR1_CONFIG_4_B,
           TRA5_TR1_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA5_TR1_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA5_TR1_CONFIG_4_B]

//>> PREP_[TRA6_TR1_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA6_TR1_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR1_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA6_TR1_CONFIG]

//>> GET_[TRA6_TR1_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA6_TR1_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR1_CONFIG;
#endif
    return fapi2::getScom(i_target, TRA6_TR1_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA6_TR1_CONFIG]

//>> PUT_[TRA6_TR1_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA6_TR1_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return fapi2::putScom(i_target, TRA6_TR1_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA6_TR1_CONFIG]


//>> SET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> CLEAR_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]
static inline bool GET_TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> CLEAR_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]
static inline bool GET_TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[TRA6_TR1_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_EXTEND_TRIG_MODE,
           TRA6_TR1_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[TRA6_TR1_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_EXTEND_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_EXTEND_TRIG_MODE,
           TRA6_TR1_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_EXTEND_TRIG_MODE]

//>> GET_[TRA6_TR1_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_EXTEND_TRIG_MODE,
           TRA6_TR1_CONFIG_EXTEND_TRIG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[TRA6_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_BANK_MODE]

//>> SET_[TRA6_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_BANK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_BANK_MODE]

//>> SET_[TRA6_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_BANK_MODE]

//>> CLEAR_[TRA6_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_BANK_MODE]

//>> GET_[TRA6_TR1_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_BANK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_BANK_MODE]

//>> GET_[TRA6_TR1_CONFIG_BANK_MODE]
static inline bool GET_TRA6_TR1_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_BANK_MODE]

//>> SET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]

//>> SET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]

//>> SET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]

//>> CLEAR_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]

//>> GET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_ENH_TRACE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]

//>> GET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]
static inline bool GET_TRA6_TR1_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_ENH_TRACE_MODE]

//>> SET_[TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> GET_[TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL,
           TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL,
           TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL]

//>> GET_[TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL,
           TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> CLEAR_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]
static inline bool GET_TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]

//>> SET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]

//>> SET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]

//>> CLEAR_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]

//>> GET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_TRACE_RUN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]

//>> GET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]
static inline bool GET_TRA6_TR1_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_TRACE_RUN_STATUS]

//>> SET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]

//>> SET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]

//>> SET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]

//>> CLEAR_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]

//>> GET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_TRACE_RUN_STICKY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]

//>> GET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]
static inline bool GET_TRA6_TR1_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_TRACE_RUN_STICKY]

//>> SET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> CLEAR_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline bool GET_TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> SET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> SET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> CLEAR_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> GET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> GET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline bool GET_TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> SET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.setBit<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> CLEAR_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return o_data.clearBit<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline bool GET_TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG));
#endif
    return i_data.getBit<TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> PREP_[TRA6_TR1_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA6_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR1_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA6_TR1_CONFIG_3]

//>> GET_[TRA6_TR1_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA6_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA6_TR1_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TRA6_TR1_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_3]

//>> PUT_[TRA6_TR1_CONFIG_3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA6_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TRA6_TR1_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA6_TR1_CONFIG_3]


//>> SET_[TRA6_TR1_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_3_C,
           TRA6_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_3_C]

//>> SET_[TRA6_TR1_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_3_C,
           TRA6_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_3_C]

//>> GET_[TRA6_TR1_CONFIG_3_C]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_3_C,
           TRA6_TR1_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_3_C]

//>> SET_[TRA6_TR1_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_3_D,
           TRA6_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA6_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_3_D]

//>> SET_[TRA6_TR1_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& SET_TRA6_TR1_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TRA6_TR1_CONFIG_3_D,
           TRA6_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA6_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA6_TR1_CONFIG_3_D]

//>> GET_[TRA6_TR1_CONFIG_3_D]
static inline fapi2::buffer<uint64_t>& GET_TRA6_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA6_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TRA6_TR1_CONFIG_3_D,
           TRA6_TR1_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA6_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA6_TR1_CONFIG_3_D]

//>> PREP_[TRA7_TR0_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA7_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA7_TR0_CONFIG]

//>> GET_[TRA7_TR0_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA7_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG;
#endif
    return fapi2::getScom(i_target, TRA7_TR0_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA7_TR0_CONFIG]

//>> PUT_[TRA7_TR0_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA7_TR0_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return fapi2::putScom(i_target, TRA7_TR0_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA7_TR0_CONFIG]


//>> SET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> CLEAR_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> GET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]
static inline bool GET_TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_STORE_ON_TRIG_MODE]

//>> SET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> CLEAR_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> GET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]
static inline bool GET_TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_WRITE_ON_RUN_MODE]

//>> SET_[TRA7_TR0_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_EXTEND_TRIG_MODE,
           TRA7_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[TRA7_TR0_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_EXTEND_TRIG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_EXTEND_TRIG_MODE,
           TRA7_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_EXTEND_TRIG_MODE]

//>> GET_[TRA7_TR0_CONFIG_EXTEND_TRIG_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_EXTEND_TRIG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_EXTEND_TRIG_MODE,
           TRA7_TR0_CONFIG_EXTEND_TRIG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_EXTEND_TRIG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_EXTEND_TRIG_MODE]

//>> SET_[TRA7_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_BANK_MODE]

//>> SET_[TRA7_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_BANK_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_BANK_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_BANK_MODE]

//>> SET_[TRA7_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_BANK_MODE]

//>> CLEAR_[TRA7_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_BANK_MODE]

//>> GET_[TRA7_TR0_CONFIG_BANK_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_BANK_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_BANK_MODE]

//>> GET_[TRA7_TR0_CONFIG_BANK_MODE]
static inline bool GET_TRA7_TR0_CONFIG_BANK_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_BANK_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_BANK_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_BANK_MODE]

//>> SET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]

//>> SET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_ENH_TRACE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]

//>> SET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]

//>> CLEAR_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]

//>> GET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_ENH_TRACE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]

//>> GET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]
static inline bool GET_TRA7_TR0_CONFIG_ENH_TRACE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_ENH_TRACE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_ENH_TRACE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_ENH_TRACE_MODE]

//>> SET_[TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> GET_[TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL,
           TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL]

//>> SET_[TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL,
           TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL,
           TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL]

//>> GET_[TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL,
           TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_TRACE_SELECT_CONTROL]

//>> SET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> CLEAR_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> GET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]
static inline bool GET_TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_TRACE_RUN_HOLD_OFF]

//>> SET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]

//>> SET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]

//>> SET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]

//>> CLEAR_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]

//>> GET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_TRACE_RUN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]

//>> GET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]
static inline bool GET_TRA7_TR0_CONFIG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_TRACE_RUN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_TRACE_RUN_STATUS]

//>> SET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]

//>> SET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]

//>> SET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]

//>> CLEAR_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]

//>> GET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_TRACE_RUN_STICKY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]

//>> GET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]
static inline bool GET_TRA7_TR0_CONFIG_TRACE_RUN_STICKY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_TRACE_RUN_STICKY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_TRACE_RUN_STICKY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_TRACE_RUN_STICKY]

//>> SET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> CLEAR_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> GET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]
static inline bool GET_TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT]

//>> SET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> SET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> SET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> CLEAR_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> GET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> GET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]
static inline bool GET_TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT]

//>> SET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> SET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.setBit<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> CLEAR_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return o_data.clearBit<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> GET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]
static inline bool GET_TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG));
#endif
    return i_data.getBit<TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT]

//>> PREP_[TRA7_TR0_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA7_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA7_TR0_CONFIG_5]

//>> GET_[TRA7_TR0_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA7_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA7_TR0_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TRA7_TR0_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_5]

//>> PUT_[TRA7_TR0_CONFIG_5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA7_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TRA7_TR0_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA7_TR0_CONFIG_5]


//>> SET_[TRA7_TR0_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_5_C,
           TRA7_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_5_C]

//>> SET_[TRA7_TR0_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_5_C,
           TRA7_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_5_C]

//>> GET_[TRA7_TR0_CONFIG_5_C]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_5_C,
           TRA7_TR0_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_5_C]

//>> SET_[TRA7_TR0_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_5_D,
           TRA7_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA7_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_5_D]

//>> SET_[TRA7_TR0_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& SET_TRA7_TR0_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TRA7_TR0_CONFIG_5_D,
           TRA7_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA7_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA7_TR0_CONFIG_5_D]

//>> GET_[TRA7_TR0_CONFIG_5_D]
static inline fapi2::buffer<uint64_t>& GET_TRA7_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA7_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TRA7_TR0_CONFIG_5_D,
           TRA7_TR0_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA7_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA7_TR0_CONFIG_5_D]

//>> PREP_[XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP_MASK_RW]

//>> GET_[XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_RW;
#endif
    return fapi2::getScom(i_target, XSTOP_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP_MASK_RW]

//>> PUT_[XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, XSTOP_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP_MASK_RW]

//>> PREP_[XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP_MASK_WO_CLEAR]

//>> GET_[XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, XSTOP_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP_MASK_WO_CLEAR]

//>> PUT_[XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, XSTOP_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP_MASK_WO_CLEAR]

//>> PREP_[XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP_MASK_WO_OR]

//>> GET_[XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, XSTOP_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP_MASK_WO_OR]

//>> PUT_[XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, XSTOP_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP_MASK_WO_OR]


//>> SET_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_01]

//>> SET_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_01]

//>> SET_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_01]

//>> CLEAR_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_01]

//>> GET_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_01]

//>> GET_[XSTOP_MASK_01]
static inline bool GET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_01]

//>> SET_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_02]

//>> SET_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_02]

//>> SET_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_02]

//>> CLEAR_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_02]

//>> GET_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_02]

//>> GET_[XSTOP_MASK_02]
static inline bool GET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_02]

//>> SET_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_03]

//>> SET_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_03]

//>> SET_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_03]

//>> CLEAR_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_03]

//>> GET_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_03]

//>> GET_[XSTOP_MASK_03]
static inline bool GET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_03]

//>> SET_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_04]

//>> SET_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_04]

//>> SET_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_04]

//>> CLEAR_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_04]

//>> GET_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_04]

//>> GET_[XSTOP_MASK_04]
static inline bool GET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_04]

//>> SET_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_05]

//>> SET_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_05]

//>> SET_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_05]

//>> CLEAR_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_05]

//>> GET_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_05]

//>> GET_[XSTOP_MASK_05]
static inline bool GET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_05]

//>> SET_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_06]

//>> SET_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_06]

//>> SET_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_06]

//>> CLEAR_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_06]

//>> GET_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_06]

//>> GET_[XSTOP_MASK_06]
static inline bool GET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_06]

//>> SET_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_07]

//>> SET_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_07]

//>> SET_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_07]

//>> CLEAR_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_07]

//>> GET_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_07]

//>> GET_[XSTOP_MASK_07]
static inline bool GET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_07]

//>> SET_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_08]

//>> SET_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_08]

//>> SET_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_08]

//>> CLEAR_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_08]

//>> GET_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_08]

//>> GET_[XSTOP_MASK_08]
static inline bool GET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_08]

//>> SET_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_09]

//>> SET_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_09]

//>> SET_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_09]

//>> CLEAR_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_09]

//>> GET_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_09]

//>> GET_[XSTOP_MASK_09]
static inline bool GET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_09]

//>> SET_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_10]

//>> SET_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_10]

//>> SET_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_10]

//>> CLEAR_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_10]

//>> GET_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_10]

//>> GET_[XSTOP_MASK_10]
static inline bool GET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_10]

//>> SET_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_11]

//>> SET_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_11]

//>> SET_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_11]

//>> CLEAR_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_11]

//>> GET_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_11]

//>> GET_[XSTOP_MASK_11]
static inline bool GET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_11]

//>> SET_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_12]

//>> SET_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_12]

//>> SET_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_12]

//>> CLEAR_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_12]

//>> GET_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_12]

//>> GET_[XSTOP_MASK_12]
static inline bool GET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_12]

//>> SET_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_13]

//>> SET_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_13]

//>> SET_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_13]

//>> CLEAR_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_13]

//>> GET_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_13]

//>> GET_[XSTOP_MASK_13]
static inline bool GET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_13]

//>> SET_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_14]

//>> SET_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_14]

//>> SET_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_14]

//>> CLEAR_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_14]

//>> GET_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_14]

//>> GET_[XSTOP_MASK_14]
static inline bool GET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_14]

//>> SET_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_15]

//>> SET_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_15]

//>> SET_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_15]

//>> CLEAR_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_15]

//>> GET_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_15]

//>> GET_[XSTOP_MASK_15]
static inline bool GET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_15]

//>> SET_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_16]

//>> SET_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_16]

//>> SET_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_16]

//>> CLEAR_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_16]

//>> GET_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_16]

//>> GET_[XSTOP_MASK_16]
static inline bool GET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_16]

//>> SET_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_17]

//>> SET_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_17]

//>> SET_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_17]

//>> CLEAR_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_17]

//>> GET_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_17]

//>> GET_[XSTOP_MASK_17]
static inline bool GET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_17]

//>> SET_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_18]

//>> SET_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_18]

//>> SET_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_18]

//>> CLEAR_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_18]

//>> GET_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_18]

//>> GET_[XSTOP_MASK_18]
static inline bool GET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_18]

//>> SET_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_19]

//>> SET_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_19]

//>> SET_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_19]

//>> CLEAR_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_19]

//>> GET_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_19]

//>> GET_[XSTOP_MASK_19]
static inline bool GET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_19]

//>> SET_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_20]

//>> SET_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_20]

//>> SET_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_20]

//>> CLEAR_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_20]

//>> GET_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_20]

//>> GET_[XSTOP_MASK_20]
static inline bool GET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_20]

//>> SET_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_21]

//>> SET_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_21]

//>> SET_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_21]

//>> CLEAR_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_21]

//>> GET_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_21]

//>> GET_[XSTOP_MASK_21]
static inline bool GET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_21]

//>> SET_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_22]

//>> SET_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_22]

//>> SET_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_22]

//>> CLEAR_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_22]

//>> GET_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_22]

//>> GET_[XSTOP_MASK_22]
static inline bool GET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_22]

//>> SET_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_23]

//>> SET_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_23]

//>> SET_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_23]

//>> CLEAR_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_23]

//>> GET_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_23]

//>> GET_[XSTOP_MASK_23]
static inline bool GET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_23]

//>> SET_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_24]

//>> SET_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_24]

//>> SET_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_24]

//>> CLEAR_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_24]

//>> GET_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_24]

//>> GET_[XSTOP_MASK_24]
static inline bool GET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_24]

//>> SET_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_25]

//>> SET_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_25]

//>> SET_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_25]

//>> CLEAR_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_25]

//>> GET_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_25]

//>> GET_[XSTOP_MASK_25]
static inline bool GET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_25]

//>> SET_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_26]

//>> SET_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_26]

//>> SET_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_26]

//>> CLEAR_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_26]

//>> GET_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_26]

//>> GET_[XSTOP_MASK_26]
static inline bool GET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_26]

//>> SET_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_27]

//>> SET_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_27]

//>> SET_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_27]

//>> CLEAR_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_27]

//>> GET_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_27]

//>> GET_[XSTOP_MASK_27]
static inline bool GET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_27]

//>> SET_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_28]

//>> SET_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_28]

//>> SET_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_28]

//>> CLEAR_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_28]

//>> GET_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_28]

//>> GET_[XSTOP_MASK_28]
static inline bool GET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_28]

//>> SET_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_29]

//>> SET_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_29]

//>> SET_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_29]

//>> CLEAR_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_29]

//>> GET_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_29]

//>> GET_[XSTOP_MASK_29]
static inline bool GET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_29]

//>> SET_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_30]

//>> SET_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_30]

//>> SET_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_30]

//>> CLEAR_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_30]

//>> GET_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_30]

//>> GET_[XSTOP_MASK_30]
static inline bool GET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_30]

//>> SET_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_31]

//>> SET_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_31]

//>> SET_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_31]

//>> CLEAR_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_31]

//>> GET_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_31]

//>> GET_[XSTOP_MASK_31]
static inline bool GET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_31]

//>> SET_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_32]

//>> SET_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_32]

//>> SET_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_32]

//>> CLEAR_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_32]

//>> GET_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_32]

//>> GET_[XSTOP_MASK_32]
static inline bool GET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_32]

//>> SET_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_33]

//>> SET_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_33]

//>> SET_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_33]

//>> CLEAR_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_33]

//>> GET_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_33]

//>> GET_[XSTOP_MASK_33]
static inline bool GET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_33]

//>> SET_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_34]

//>> SET_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_34]

//>> SET_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_34]

//>> CLEAR_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_34]

//>> GET_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_34]

//>> GET_[XSTOP_MASK_34]
static inline bool GET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_34]

//>> SET_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_35]

//>> SET_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_35]

//>> SET_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_35]

//>> CLEAR_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_35]

//>> GET_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_35]

//>> GET_[XSTOP_MASK_35]
static inline bool GET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_35]

//>> SET_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_36]

//>> SET_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_36]

//>> SET_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_36]

//>> CLEAR_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_36]

//>> GET_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_36]

//>> GET_[XSTOP_MASK_36]
static inline bool GET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_36]

//>> SET_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_37]

//>> SET_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_37]

//>> SET_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_37]

//>> CLEAR_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_37]

//>> GET_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_37]

//>> GET_[XSTOP_MASK_37]
static inline bool GET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_37]

//>> SET_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_38]

//>> SET_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_38]

//>> SET_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_38]

//>> CLEAR_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_38]

//>> GET_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_38]

//>> GET_[XSTOP_MASK_38]
static inline bool GET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_38]

//>> SET_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_39]

//>> SET_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_39]

//>> SET_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_39]

//>> CLEAR_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_39]

//>> GET_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_39]

//>> GET_[XSTOP_MASK_39]
static inline bool GET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_39]

//>> SET_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_40]

//>> SET_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_40]

//>> SET_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_40]

//>> CLEAR_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_40]

//>> GET_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_40]

//>> GET_[XSTOP_MASK_40]
static inline bool GET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_40]

//>> SET_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_41]

//>> SET_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_41]

//>> SET_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_41]

//>> CLEAR_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_41]

//>> GET_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_41]

//>> GET_[XSTOP_MASK_41]
static inline bool GET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_41]

//>> SET_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_42]

//>> SET_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_42]

//>> SET_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_42]

//>> CLEAR_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_42]

//>> GET_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_42]

//>> GET_[XSTOP_MASK_42]
static inline bool GET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_42]

//>> SET_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_43]

//>> SET_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_43]

//>> SET_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_43]

//>> CLEAR_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_43]

//>> GET_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_43]

//>> GET_[XSTOP_MASK_43]
static inline bool GET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_43]

//>> SET_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_44]

//>> SET_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_44]

//>> SET_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_44]

//>> CLEAR_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_44]

//>> GET_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_44]

//>> GET_[XSTOP_MASK_44]
static inline bool GET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_44]

//>> SET_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_45]

//>> SET_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_45]

//>> SET_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_45]

//>> CLEAR_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_45]

//>> GET_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_45]

//>> GET_[XSTOP_MASK_45]
static inline bool GET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_45]

//>> SET_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_46]

//>> SET_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_46]

//>> SET_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_46]

//>> CLEAR_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_46]

//>> GET_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_46]

//>> GET_[XSTOP_MASK_46]
static inline bool GET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_46]

//>> SET_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_47]

//>> SET_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_47]

//>> SET_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_47]

//>> CLEAR_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_47]

//>> GET_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_47]

//>> GET_[XSTOP_MASK_47]
static inline bool GET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_47]

//>> SET_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_48]

//>> SET_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_48]

//>> SET_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_48]

//>> CLEAR_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_48]

//>> GET_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_48]

//>> GET_[XSTOP_MASK_48]
static inline bool GET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_48]

//>> SET_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_49]

//>> SET_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_49]

//>> SET_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_49]

//>> CLEAR_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_49]

//>> GET_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_49]

//>> GET_[XSTOP_MASK_49]
static inline bool GET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_49]

//>> SET_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_50]

//>> SET_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_50]

//>> SET_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_50]

//>> CLEAR_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_50]

//>> GET_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_50]

//>> GET_[XSTOP_MASK_50]
static inline bool GET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_50]

//>> SET_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_51]

//>> SET_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_51]

//>> SET_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_51]

//>> CLEAR_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_51]

//>> GET_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_51]

//>> GET_[XSTOP_MASK_51]
static inline bool GET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_51]

//>> SET_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_52]

//>> SET_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_52]

//>> SET_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_52]

//>> CLEAR_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_52]

//>> GET_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_52]

//>> GET_[XSTOP_MASK_52]
static inline bool GET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_52]

//>> SET_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_53]

//>> SET_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_53]

//>> SET_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_53]

//>> CLEAR_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_53]

//>> GET_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_53]

//>> GET_[XSTOP_MASK_53]
static inline bool GET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_53]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
