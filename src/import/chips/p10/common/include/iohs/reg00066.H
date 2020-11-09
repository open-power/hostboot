/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00066.H $         */
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

#ifndef __IOHS_REG00066_H_
#define __IOHS_REG00066_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[SLAVE_CONFIG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SLAVE_CONFIG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SLAVE_CONFIG_REG]

//>> GET_[SLAVE_CONFIG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SLAVE_CONFIG_REG;
#endif
    return fapi2::getScom(i_target, SLAVE_CONFIG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SLAVE_CONFIG_REG]

//>> PUT_[SLAVE_CONFIG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SLAVE_CONFIG_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return fapi2::putScom(i_target, SLAVE_CONFIG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SLAVE_CONFIG_REG]


//>> SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN]

//>> SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> CLEAR_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> GET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> GET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]
static inline bool GET_SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_HEARTBEAT]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> CLEAR_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> GET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]
static inline bool GET_SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO]

//>> SET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> CLEAR_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_PM_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_PM_DISABLE]
static inline bool GET_SLAVE_CONFIG_REG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_PM_DISABLE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> CLEAR_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_PM_MUX_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> GET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]
static inline bool GET_SLAVE_CONFIG_REG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_PM_MUX_DISABLE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE]

//>> SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> CLEAR_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]
static inline bool GET_SLAVE_CONFIG_REG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PCBSL_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_MASK_PLL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]

//>> GET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_MASK_PLL_ERRS,
           SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_MASK_PLL_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS,
           P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS,
           P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS,
           P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS]

//>> SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_QME_PAR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> CLEAR_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> GET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_QME_PAR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> GET_[SLAVE_CONFIG_REG_QME_PAR_DIS]
static inline bool GET_SLAVE_CONFIG_REG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_QME_PAR_DIS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS]

//>> SET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> SET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_FORCE_0_QME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<SLAVE_CONFIG_REG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> SET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<SLAVE_CONFIG_REG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> CLEAR_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& CLEAR_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<SLAVE_CONFIG_REG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> GET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& GET_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<SLAVE_CONFIG_REG_FORCE_0_QME,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> GET_[SLAVE_CONFIG_REG_FORCE_0_QME]
static inline bool GET_SLAVE_CONFIG_REG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<SLAVE_CONFIG_REG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access SLAVE_CONFIG_REG_FORCE_0_QME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SLAVE_CONFIG_REG_FORCE_0_QME]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> SET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> GET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME]

//>> SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.insertFromRight<P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.setBit<P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> CLEAR_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return o_data.clearBit<P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.extractToRight<P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]

//>> GET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]
static inline bool GET_P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SLAVE_CONFIG_REG));
#endif
    return i_data.getBit<P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
