/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00077.H $         */
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

#ifndef __PROC_REG00077_H_
#define __PROC_REG00077_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_STAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_STAT;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_STAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_STAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3,
           TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3,
           TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3,
           TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_1_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_INVALID_NUMBER_OF_FRAMES]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_STAT));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CMD1B_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD1B_CLEAR_STICKY_BITS_1B]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD1B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD1B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD1B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD1B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD1B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD1B_OCB_OCI_O2SWD1B_O2S_WDATA_1B]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_SPARE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_BAR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3_LINEAR_WINDOW_MASK]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_LINEAR_WINDOW_SCRESP]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3_SPARE0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0_START]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1_PULL_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1,
           TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1,
           TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCS1_RW, TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCS1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1,
           TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCS1_OCB_OCI_OCCS1_OCC_SCRATCH_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OITR1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR1_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OITR1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OITR1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR1_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1,
           TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1,
           TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OITR1_RW, TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1,
           TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OITR1_OCB_OCI_OITR1_INTERRUPT_TYPE_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q0_OCB_OCI_OPIT1Q0RR_PCB_INTR_PAYLOAD]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RDATA_OCB_OCI_P2S_RDATA]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_RESET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_RESET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_RESET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_RESET;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_RESET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_RESET(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RESET));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_RESET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RESET));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET,
           TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RESET));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET,
           TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_RESET));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET,
           TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_RESET_OCB_OCI_P2S_RESET]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA,
           TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA_OCB_OCI_P2S_WDATA]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_SPARE2]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0_OCB_PIB_OCBDR0_DATA]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3_OCB_PIB_OCBESR3_ERROR_ADDR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_JTAG_TDO]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_SRC_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_RUN_TCK]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_TCK_WIDTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_JTAG_TRST_B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJCFG_DBG_HALT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_JTAG_INPROG]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_SRC_SEL_EQ1_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_RUN_TCK_EQ0_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_TRST_B_EQ0_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_IR_DR_EQ0_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_INPROG_WR_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJSTAT_FSM_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_DR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_DO_TAP_RESET]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_WR_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OJTDO_OCB_PIB_OJIC_JTAG_INSTR]

//>> PREP_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_SRAM_CTL_SRBV3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3]

//>> GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3]

//>> PUT_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_SRAM_CTL_SRBV3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3]


//>> SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3]

//>> SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3]

//>> GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV3_SRAM_SRBV3_BOOT_VECTOR_WORD3]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
