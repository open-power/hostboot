/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00012.H $         */
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

#ifndef __IOHS_REG00012_H_
#define __IOHS_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[DLP_MISC_ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_MISC_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_MISC_ERROR_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_MISC_ERROR_STATUS]

//>> GET_[DLP_MISC_ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_MISC_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_MISC_ERROR_STATUS;
#endif
    return fapi2::getScom(i_target, DLP_MISC_ERROR_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS]

//>> PUT_[DLP_MISC_ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_MISC_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return fapi2::putScom(i_target, DLP_MISC_ERROR_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_MISC_ERROR_STATUS]


//>> SET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]

//>> SET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]

//>> SET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]

//>> CLEAR_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]

//>> GET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]

//>> GET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]
static inline bool GET_DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER]

//>> SET_[DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS]

//>> SET_[DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS]

//>> GET_[DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS]

//>> SET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> CLEAR_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline bool GET_DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]

//>> CLEAR_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]
static inline bool GET_DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]

//>> CLEAR_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]
static inline bool GET_DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]

//>> CLEAR_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]
static inline bool GET_DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]

//>> CLEAR_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]
static inline bool GET_DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]

//>> CLEAR_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]
static inline bool GET_DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]

//>> CLEAR_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]

//>> GET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]
static inline bool GET_DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR]

//>> SET_[DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS]

//>> SET_[DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS]

//>> GET_[DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS]

//>> SET_[DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS]

//>> SET_[DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS]

//>> GET_[DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS]

//>> SET_[DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS]

//>> SET_[DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS]

//>> GET_[DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS]

//>> SET_[DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS]

//>> SET_[DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS]

//>> GET_[DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS]
static inline fapi2::buffer<uint64_t>& GET_DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_MISC_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS,
           DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
