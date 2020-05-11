/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00027.H $         */
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

#ifndef __PERV_REG00027_H_
#define __PERV_REG00027_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[TOD_PSS_MSS_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_PSS_MSS_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_PSS_MSS_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_PSS_MSS_STATUS_REG]

//>> GET_[TOD_PSS_MSS_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_PSS_MSS_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_PSS_MSS_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TOD_PSS_MSS_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG]

//>> PUT_[TOD_PSS_MSS_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_PSS_MSS_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TOD_PSS_MSS_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_PSS_MSS_STATUS_REG]


//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT,
           TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT,
           TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT]

//>> GET_[TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT,
           TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT]

//>> SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]

//>> SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]

//>> SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]

//>> GET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]

//>> GET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]

//>> GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]

//>> GET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_IS_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_IS_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_IS_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_IS_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_IS_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_RUNNING]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_PRIMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_PRIMARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_IS_PRIMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_IS_PRIMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_IS_PRIMARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_IS_PRIMARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_IS_PRIMARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_PRIMARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_PRIMARY]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_SECONDARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_SECONDARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_IS_SECONDARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_IS_SECONDARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_IS_SECONDARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_IS_SECONDARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_IS_SECONDARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SECONDARY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_SECONDARY]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_SLAVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_IS_SLAVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]

//>> SET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_IS_SLAVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_IS_SLAVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_IS_SLAVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]

//>> GET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_IS_SLAVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_IS_SLAVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_IS_SLAVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_IS_SLAVE]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]

//>> GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]

//>> GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH]

//>> SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]

//>> SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]

//>> SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]

//>> GET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]

//>> GET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]

//>> SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]

//>> CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]

//>> GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]
static inline bool GET_TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_STATUS_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER]

//>> PREP_[TOD_S_PATH_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_S_PATH_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_S_PATH_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_S_PATH_STATUS_REG]

//>> GET_[TOD_S_PATH_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_S_PATH_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_S_PATH_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TOD_S_PATH_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_S_PATH_STATUS_REG]

//>> PUT_[TOD_S_PATH_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_S_PATH_STATUS_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TOD_S_PATH_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_S_PATH_STATUS_REG]


//>> SET_[TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE,
           TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE]

//>> SET_[TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE,
           TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE]

//>> GET_[TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE,
           TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE]

//>> SET_[TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE,
           TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE]

//>> SET_[TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE,
           TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE]

//>> GET_[TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE,
           TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE]

//>> SET_[TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO,
           TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO]

//>> SET_[TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO,
           TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO]

//>> GET_[TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO,
           TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO]

//>> SET_[TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15,
           TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15]

//>> SET_[TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15,
           TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15]

//>> GET_[TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15,
           TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15]

//>> SET_[TOD_S_PATH_STATUS_REG_S_PATH_0_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_S_PATH_0_CPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_S_PATH_0_CPS,
           TOD_S_PATH_STATUS_REG_S_PATH_0_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_0_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_S_PATH_0_CPS]

//>> SET_[TOD_S_PATH_STATUS_REG_S_PATH_0_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_S_PATH_0_CPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_S_PATH_0_CPS,
           TOD_S_PATH_STATUS_REG_S_PATH_0_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_0_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_S_PATH_0_CPS]

//>> GET_[TOD_S_PATH_STATUS_REG_S_PATH_0_CPS]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_STATUS_REG_S_PATH_0_CPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_STATUS_REG_S_PATH_0_CPS,
           TOD_S_PATH_STATUS_REG_S_PATH_0_CPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_0_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_STATUS_REG_S_PATH_0_CPS]

//>> SET_[TOD_S_PATH_STATUS_REG_S_PATH_1_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_S_PATH_1_CPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_S_PATH_1_CPS,
           TOD_S_PATH_STATUS_REG_S_PATH_1_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_1_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_S_PATH_1_CPS]

//>> SET_[TOD_S_PATH_STATUS_REG_S_PATH_1_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_S_PATH_1_CPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_S_PATH_1_CPS,
           TOD_S_PATH_STATUS_REG_S_PATH_1_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_1_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_S_PATH_1_CPS]

//>> GET_[TOD_S_PATH_STATUS_REG_S_PATH_1_CPS]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_STATUS_REG_S_PATH_1_CPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_STATUS_REG_S_PATH_1_CPS,
           TOD_S_PATH_STATUS_REG_S_PATH_1_CPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_1_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_STATUS_REG_S_PATH_1_CPS]

//>> SET_[TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT,
           TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT]

//>> SET_[TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT,
           TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT]

//>> GET_[TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT,
           TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT]

//>> SET_[TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT,
           TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT]

//>> SET_[TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT,
           TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT]

//>> GET_[TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT,
           TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
