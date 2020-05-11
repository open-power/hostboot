/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00015.H $            */
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

#ifndef __C_REG00015_H_
#define __C_REG00015_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_TFAC_HOLD_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_TFAC_HOLD_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_TFAC_HOLD_OUT;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_TFAC_HOLD_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]

//>> PUT_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_TFAC_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_TFAC_HOLD_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT]


//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT,
           EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>> GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]
static inline bool GET_EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_TFAC_HOLD_OUT));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
