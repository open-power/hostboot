/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00025.H $         */
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

#ifndef __PERV_REG00025_H_
#define __PERV_REG00025_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[TOD_PRI_PORT_0_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_PRI_PORT_0_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_PRI_PORT_0_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_PRI_PORT_0_CTRL_REG]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_PRI_PORT_0_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_PRI_PORT_0_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_PRI_PORT_0_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG]

//>> PUT_[TOD_PRI_PORT_0_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_PRI_PORT_0_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_PRI_PORT_0_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_PRI_PORT_0_CTRL_REG]


//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]

//>> CLEAR_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]
static inline bool GET_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT,
           TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]
static inline bool GET_TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31,
           TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31,
           TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31,
           TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31]

//>> SET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29,
           P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29]

//>> SET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29,
           P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29]

//>> GET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29,
           P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29]

//>> SET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE,
           P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]

//>> SET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE,
           P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]

//>> GET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE,
           P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE,
           TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]

//>> SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE,
           TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]

//>> GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TOD_PRI_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE,
           TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
