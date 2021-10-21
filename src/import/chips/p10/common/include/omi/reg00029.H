/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/omi/reg00029.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __OMI_REG00029_H_
#define __OMI_REG00029_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> PREP_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL;
#endif
    return fapi2::getScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL]

//>> PUT_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return fapi2::putScom(i_target, TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL]


//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE,
           TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& SET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.setBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return o_data.clearBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline fapi2::buffer<uint64_t>& GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.extractToRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>> GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]
static inline bool GET_TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL));
#endif
    return i_data.getBit<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_omi Invalid dial access TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
