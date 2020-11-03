/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00029.H $         */
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

#ifndef __PERV_REG00029_H_
#define __PERV_REG00029_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[TOD_SEC_PORT_1_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_SEC_PORT_1_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_SEC_PORT_1_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_SEC_PORT_1_CTRL_REG]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_SEC_PORT_1_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_SEC_PORT_1_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_SEC_PORT_1_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG]

//>> PUT_[TOD_SEC_PORT_1_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_SEC_PORT_1_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_SEC_PORT_1_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_SEC_PORT_1_CTRL_REG]


//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]

//>> CLEAR_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]
static inline bool GET_TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT,
           TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31,
           TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31]

//>> SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31,
           TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31]

//>> GET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_1_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31,
           TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31]

//>> PREP_[TOD_S_PATH_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_S_PATH_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_S_PATH_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_S_PATH_CTRL_REG]

//>> GET_[TOD_S_PATH_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_S_PATH_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_S_PATH_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_S_PATH_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG]

//>> PUT_[TOD_S_PATH_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_S_PATH_CTRL_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_S_PATH_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_S_PATH_CTRL_REG]


//>> SET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]

//>> SET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]

//>> SET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]

//>> GET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]

//>> GET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]
static inline bool GET_TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT]

//>> SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]

//>> SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]

//>> SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]

//>> GET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]

//>> GET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]
static inline bool GET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]
static inline bool GET_TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]
static inline bool GET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]

//>> SET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]

//>> SET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]

//>> GET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]

//>> GET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]
static inline bool GET_TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT]

//>> SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]

//>> SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]

//>> SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]

//>> GET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]

//>> GET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]
static inline bool GET_TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR,
           TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR,
           TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR,
           TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION,
           TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION,
           TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION,
           TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline bool GET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT,
           TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT,
           TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT,
           TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION,
           TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION,
           TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION,
           TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline bool GET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT,
           TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT,
           TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT,
           TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]
static inline bool GET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]

//>> CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]
static inline bool GET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR,
           TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR,
           TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR,
           TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION,
           TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION,
           TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION,
           TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX,
           TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX]

//>> SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX]
static inline fapi2::buffer<uint64_t>& SET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX,
           TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX]

//>> GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX]
static inline fapi2::buffer<uint64_t>& GET_TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_S_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX,
           TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX]

//>> PREP_[TOD_TX_TTYPE_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_TX_TTYPE_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TX_TTYPE_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_TX_TTYPE_CTRL_REG]

//>> GET_[TOD_TX_TTYPE_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_TX_TTYPE_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TX_TTYPE_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_TX_TTYPE_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG]

//>> PUT_[TOD_TX_TTYPE_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_TX_TTYPE_CTRL_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_TX_TTYPE_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_TX_TTYPE_CTRL_REG]


//>> SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS,
           TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS,
           TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS,
           TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID,
           TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID,
           TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID,
           TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.setBit<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]

//>> CLEAR_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.clearBit<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]
static inline bool GET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.getBit<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.setBit<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]

//>> CLEAR_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.clearBit<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]
static inline bool GET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.getBit<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.setBit<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]

//>> CLEAR_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.clearBit<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]
static inline bool GET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.getBit<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.setBit<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]

//>> CLEAR_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.clearBit<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]
static inline bool GET_TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.getBit<TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.setBit<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]

//>> CLEAR_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.clearBit<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]
static inline bool GET_TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.getBit<TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE,
           TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE]

//>> SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE,
           TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE]

//>> GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE,
           TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE]

//>> PREP_[XSTOP2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP2]

//>> GET_[XSTOP2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP2(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP2;
#endif
    return fapi2::getScom(i_target, XSTOP2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP2]

//>> PUT_[XSTOP2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return fapi2::putScom(i_target, XSTOP2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP2]


//>> SET_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_ENABLE]

//>> SET_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_ENABLE]

//>> SET_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_ENABLE]

//>> CLEAR_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_ENABLE]

//>> GET_[XSTOP2_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_ENABLE]

//>> GET_[XSTOP2_ENABLE]
static inline bool GET_XSTOP2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_ENABLE]

//>> SET_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_SNOPA]

//>> SET_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_SNOPA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_SNOPA]

//>> SET_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_SNOPA]

//>> CLEAR_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_WAIT_SNOPA]

//>> GET_[XSTOP2_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_WAIT_SNOPA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_SNOPA]

//>> GET_[XSTOP2_WAIT_SNOPA]
static inline bool GET_XSTOP2_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_SNOPA]

//>> SET_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_TRIGGER_OPCG_GO]

//>> SET_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_TRIGGER_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_TRIGGER_OPCG_GO]

//>> SET_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_TRIGGER_OPCG_GO]

//>> CLEAR_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_TRIGGER_OPCG_GO]

//>> GET_[XSTOP2_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_TRIGGER_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_TRIGGER_OPCG_GO]

//>> GET_[XSTOP2_TRIGGER_OPCG_GO]
static inline bool GET_XSTOP2_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_TRIGGER_OPCG_GO]

//>> SET_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_ALWAYS]

//>> SET_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_ALWAYS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_ALWAYS]

//>> SET_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_ALWAYS]

//>> CLEAR_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_WAIT_ALWAYS]

//>> GET_[XSTOP2_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_WAIT_ALWAYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_ALWAYS]

//>> GET_[XSTOP2_WAIT_ALWAYS]
static inline bool GET_XSTOP2_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_ALWAYS]

//>> SET_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_PERV]

//>> SET_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_PERV]

//>> SET_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_PERV]

//>> CLEAR_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_PERV]

//>> GET_[XSTOP2_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_PERV]

//>> GET_[XSTOP2_REGION_PERV]
static inline bool GET_XSTOP2_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_PERV]

//>> SET_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT1]

//>> SET_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT1]

//>> SET_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT1]

//>> CLEAR_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT1]

//>> GET_[XSTOP2_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT1]

//>> GET_[XSTOP2_REGION_UNIT1]
static inline bool GET_XSTOP2_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT1]

//>> SET_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT2]

//>> SET_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT2]

//>> SET_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT2]

//>> CLEAR_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT2]

//>> GET_[XSTOP2_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT2]

//>> GET_[XSTOP2_REGION_UNIT2]
static inline bool GET_XSTOP2_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT2]

//>> SET_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT3]

//>> SET_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT3]

//>> SET_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT3]

//>> CLEAR_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT3]

//>> GET_[XSTOP2_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT3]

//>> GET_[XSTOP2_REGION_UNIT3]
static inline bool GET_XSTOP2_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT3]

//>> SET_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT4]

//>> SET_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT4]

//>> SET_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT4]

//>> CLEAR_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT4]

//>> GET_[XSTOP2_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT4]

//>> GET_[XSTOP2_REGION_UNIT4]
static inline bool GET_XSTOP2_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT4]

//>> SET_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT5]

//>> SET_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT5]

//>> SET_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT5]

//>> CLEAR_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT5]

//>> GET_[XSTOP2_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT5]

//>> GET_[XSTOP2_REGION_UNIT5]
static inline bool GET_XSTOP2_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT5]

//>> SET_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT6]

//>> SET_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT6]

//>> SET_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT6]

//>> CLEAR_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT6]

//>> GET_[XSTOP2_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT6]

//>> GET_[XSTOP2_REGION_UNIT6]
static inline bool GET_XSTOP2_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT6]

//>> SET_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT7]

//>> SET_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT7]

//>> SET_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT7]

//>> CLEAR_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT7]

//>> GET_[XSTOP2_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT7]

//>> GET_[XSTOP2_REGION_UNIT7]
static inline bool GET_XSTOP2_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT7]

//>> SET_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT8]

//>> SET_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT8]

//>> SET_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT8]

//>> CLEAR_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT8]

//>> GET_[XSTOP2_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT8]

//>> GET_[XSTOP2_REGION_UNIT8]
static inline bool GET_XSTOP2_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT8]

//>> SET_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT9]

//>> SET_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT9]

//>> SET_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT9]

//>> CLEAR_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT9]

//>> GET_[XSTOP2_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT9]

//>> GET_[XSTOP2_REGION_UNIT9]
static inline bool GET_XSTOP2_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT9]

//>> SET_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT10]

//>> SET_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT10]

//>> SET_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT10]

//>> CLEAR_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT10]

//>> GET_[XSTOP2_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT10]

//>> GET_[XSTOP2_REGION_UNIT10]
static inline bool GET_XSTOP2_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT10]

//>> SET_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT11]

//>> SET_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT11]

//>> SET_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT11]

//>> CLEAR_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT11]

//>> GET_[XSTOP2_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT11]

//>> GET_[XSTOP2_REGION_UNIT11]
static inline bool GET_XSTOP2_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT11]

//>> SET_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT12]

//>> SET_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT12]

//>> SET_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT12]

//>> CLEAR_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT12]

//>> GET_[XSTOP2_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT12]

//>> GET_[XSTOP2_REGION_UNIT12]
static inline bool GET_XSTOP2_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT12]

//>> SET_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT13]

//>> SET_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT13]

//>> SET_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT13]

//>> CLEAR_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT13]

//>> GET_[XSTOP2_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT13]

//>> GET_[XSTOP2_REGION_UNIT13]
static inline bool GET_XSTOP2_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT13]

//>> SET_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT14]

//>> SET_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT14]

//>> SET_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.setBit<XSTOP2_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_REGION_UNIT14]

//>> CLEAR_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.clearBit<XSTOP2_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP2_REGION_UNIT14]

//>> GET_[XSTOP2_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT14]

//>> GET_[XSTOP2_REGION_UNIT14]
static inline bool GET_XSTOP2_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.getBit<XSTOP2_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP2_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_REGION_UNIT14]

//>> SET_[XSTOP2_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_CYCLES,
           XSTOP2_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP2_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_CYCLES]

//>> SET_[XSTOP2_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP2_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return o_data.insertFromRight<XSTOP2_WAIT_CYCLES,
           XSTOP2_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP2_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP2_WAIT_CYCLES]

//>> GET_[XSTOP2_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_XSTOP2_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP2));
#endif
    return i_data.extractToRight<XSTOP2_WAIT_CYCLES,
           XSTOP2_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP2_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP2_WAIT_CYCLES]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
