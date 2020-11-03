/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00025.H $         */
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

#ifndef __IOHS_REG00025_H_
#define __IOHS_REG00025_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[DLP_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_FIR_REG_RW]

//>> GET_[DLP_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, DLP_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_FIR_REG_RW]

//>> PUT_[DLP_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, DLP_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_FIR_REG_RW]

//>> PREP_[DLP_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_FIR_REG_WO_AND]

//>> GET_[DLP_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, DLP_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_FIR_REG_WO_AND]

//>> PUT_[DLP_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, DLP_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_FIR_REG_WO_AND]

//>> PREP_[DLP_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_FIR_REG_WO_OR]

//>> GET_[DLP_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, DLP_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_FIR_REG_WO_OR]

//>> PUT_[DLP_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, DLP_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_FIR_REG_WO_OR]


//>> SET_[DLP_FIR_REG_0_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TRAINED]

//>> SET_[DLP_FIR_REG_0_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TRAINED]

//>> SET_[DLP_FIR_REG_0_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TRAINED]

//>> CLEAR_[DLP_FIR_REG_0_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_TRAINED]

//>> GET_[DLP_FIR_REG_0_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TRAINED]

//>> GET_[DLP_FIR_REG_0_TRAINED]
static inline bool GET_DLP_FIR_REG_0_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TRAINED]

//>> SET_[DLP_FIR_REG_1_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TRAINED]

//>> SET_[DLP_FIR_REG_1_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TRAINED]

//>> SET_[DLP_FIR_REG_1_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TRAINED]

//>> CLEAR_[DLP_FIR_REG_1_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_TRAINED]

//>> GET_[DLP_FIR_REG_1_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TRAINED]

//>> GET_[DLP_FIR_REG_1_TRAINED]
static inline bool GET_DLP_FIR_REG_1_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TRAINED]

//>> SET_[DLP_FIR_REG_0_OP_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_OP_IRQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_OP_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_OP_IRQ]

//>> SET_[DLP_FIR_REG_0_OP_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_OP_IRQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_OP_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_OP_IRQ]

//>> SET_[DLP_FIR_REG_0_OP_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_OP_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_OP_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_OP_IRQ]

//>> CLEAR_[DLP_FIR_REG_0_OP_IRQ]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_OP_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_OP_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_OP_IRQ]

//>> GET_[DLP_FIR_REG_0_OP_IRQ]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_OP_IRQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_OP_IRQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_OP_IRQ]

//>> GET_[DLP_FIR_REG_0_OP_IRQ]
static inline bool GET_DLP_FIR_REG_0_OP_IRQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_OP_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_OP_IRQ]

//>> SET_[DLP_FIR_REG_1_OP_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_OP_IRQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_OP_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_OP_IRQ]

//>> SET_[DLP_FIR_REG_1_OP_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_OP_IRQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_OP_IRQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_OP_IRQ]

//>> SET_[DLP_FIR_REG_1_OP_IRQ]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_OP_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_OP_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_OP_IRQ]

//>> CLEAR_[DLP_FIR_REG_1_OP_IRQ]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_OP_IRQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_OP_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_OP_IRQ]

//>> GET_[DLP_FIR_REG_1_OP_IRQ]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_OP_IRQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_OP_IRQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_OP_IRQ]

//>> GET_[DLP_FIR_REG_1_OP_IRQ]
static inline bool GET_DLP_FIR_REG_1_OP_IRQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_OP_IRQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_OP_IRQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_OP_IRQ]

//>> SET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_REPLAY_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]

//>> SET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_REPLAY_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_REPLAY_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]

//>> SET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_REPLAY_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]

//>> CLEAR_[DLP_FIR_REG_0_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_REPLAY_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_REPLAY_THRESHOLD]

//>> GET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_REPLAY_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]

//>> GET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]
static inline bool GET_DLP_FIR_REG_0_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_REPLAY_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_REPLAY_THRESHOLD]

//>> SET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_REPLAY_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]

//>> SET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_REPLAY_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_REPLAY_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]

//>> SET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_REPLAY_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]

//>> CLEAR_[DLP_FIR_REG_1_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_REPLAY_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_REPLAY_THRESHOLD]

//>> GET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_REPLAY_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]

//>> GET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]
static inline bool GET_DLP_FIR_REG_1_REPLAY_THRESHOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_REPLAY_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_REPLAY_THRESHOLD]

//>> SET_[DLP_FIR_REG_0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_CRC_ERROR]

//>> SET_[DLP_FIR_REG_0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_CRC_ERROR]

//>> SET_[DLP_FIR_REG_0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_CRC_ERROR]

//>> CLEAR_[DLP_FIR_REG_0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_CRC_ERROR]

//>> GET_[DLP_FIR_REG_0_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_CRC_ERROR]

//>> GET_[DLP_FIR_REG_0_CRC_ERROR]
static inline bool GET_DLP_FIR_REG_0_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_CRC_ERROR]

//>> SET_[DLP_FIR_REG_1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_CRC_ERROR]

//>> SET_[DLP_FIR_REG_1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_CRC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_CRC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_CRC_ERROR]

//>> SET_[DLP_FIR_REG_1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_CRC_ERROR]

//>> CLEAR_[DLP_FIR_REG_1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_CRC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_CRC_ERROR]

//>> GET_[DLP_FIR_REG_1_CRC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_CRC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_CRC_ERROR]

//>> GET_[DLP_FIR_REG_1_CRC_ERROR]
static inline bool GET_DLP_FIR_REG_1_CRC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_CRC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_CRC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_CRC_ERROR]

//>> SET_[DLP_FIR_REG_0_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NAK_RECEIVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_NAK_RECEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NAK_RECEIVED]

//>> SET_[DLP_FIR_REG_0_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NAK_RECEIVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_NAK_RECEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NAK_RECEIVED]

//>> SET_[DLP_FIR_REG_0_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NAK_RECEIVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_NAK_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NAK_RECEIVED]

//>> CLEAR_[DLP_FIR_REG_0_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_NAK_RECEIVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_NAK_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_NAK_RECEIVED]

//>> GET_[DLP_FIR_REG_0_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_NAK_RECEIVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_NAK_RECEIVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_NAK_RECEIVED]

//>> GET_[DLP_FIR_REG_0_NAK_RECEIVED]
static inline bool GET_DLP_FIR_REG_0_NAK_RECEIVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_NAK_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_NAK_RECEIVED]

//>> SET_[DLP_FIR_REG_1_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NAK_RECEIVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_NAK_RECEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NAK_RECEIVED]

//>> SET_[DLP_FIR_REG_1_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NAK_RECEIVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_NAK_RECEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NAK_RECEIVED]

//>> SET_[DLP_FIR_REG_1_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NAK_RECEIVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_NAK_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NAK_RECEIVED]

//>> CLEAR_[DLP_FIR_REG_1_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_NAK_RECEIVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_NAK_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_NAK_RECEIVED]

//>> GET_[DLP_FIR_REG_1_NAK_RECEIVED]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_NAK_RECEIVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_NAK_RECEIVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_NAK_RECEIVED]

//>> GET_[DLP_FIR_REG_1_NAK_RECEIVED]
static inline bool GET_DLP_FIR_REG_1_NAK_RECEIVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_NAK_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_NAK_RECEIVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_NAK_RECEIVED]

//>> SET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_REPLAY_BUFFER_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]

//>> SET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_REPLAY_BUFFER_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_REPLAY_BUFFER_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]

//>> SET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_REPLAY_BUFFER_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]

//>> CLEAR_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_REPLAY_BUFFER_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]

//>> GET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_REPLAY_BUFFER_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]

//>> GET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]
static inline bool GET_DLP_FIR_REG_0_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_REPLAY_BUFFER_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_REPLAY_BUFFER_FULL]

//>> SET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_REPLAY_BUFFER_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]

//>> SET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_REPLAY_BUFFER_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_REPLAY_BUFFER_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]

//>> SET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_REPLAY_BUFFER_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]

//>> CLEAR_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_REPLAY_BUFFER_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]

//>> GET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_REPLAY_BUFFER_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]

//>> GET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]
static inline bool GET_DLP_FIR_REG_1_REPLAY_BUFFER_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_REPLAY_BUFFER_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_REPLAY_BUFFER_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_REPLAY_BUFFER_FULL]

//>> SET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SL_ECC_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]

//>> SET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SL_ECC_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SL_ECC_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]

//>> SET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_SL_ECC_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]

//>> CLEAR_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_SL_ECC_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]

//>> GET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_SL_ECC_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]

//>> GET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]
static inline bool GET_DLP_FIR_REG_0_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_SL_ECC_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SL_ECC_THRESHOLD]

//>> SET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SL_ECC_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]

//>> SET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SL_ECC_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SL_ECC_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]

//>> SET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_SL_ECC_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]

//>> CLEAR_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_SL_ECC_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]

//>> GET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_SL_ECC_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]

//>> GET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]
static inline bool GET_DLP_FIR_REG_1_SL_ECC_THRESHOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_SL_ECC_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SL_ECC_THRESHOLD]

//>> SET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SL_ECC_CORRECTABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]

//>> SET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SL_ECC_CORRECTABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SL_ECC_CORRECTABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]

//>> SET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_SL_ECC_CORRECTABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]

//>> CLEAR_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_SL_ECC_CORRECTABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]

//>> GET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_SL_ECC_CORRECTABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]

//>> GET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]
static inline bool GET_DLP_FIR_REG_0_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_SL_ECC_CORRECTABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SL_ECC_CORRECTABLE]

//>> SET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SL_ECC_CORRECTABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]

//>> SET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SL_ECC_CORRECTABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SL_ECC_CORRECTABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]

//>> SET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_SL_ECC_CORRECTABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]

//>> CLEAR_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_SL_ECC_CORRECTABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]

//>> GET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_SL_ECC_CORRECTABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]

//>> GET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]
static inline bool GET_DLP_FIR_REG_1_SL_ECC_CORRECTABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_SL_ECC_CORRECTABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_CORRECTABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SL_ECC_CORRECTABLE]

//>> SET_[DLP_FIR_REG_0_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SL_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SL_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SL_ECC_UE]

//>> SET_[DLP_FIR_REG_0_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SL_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SL_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SL_ECC_UE]

//>> SET_[DLP_FIR_REG_0_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SL_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_SL_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SL_ECC_UE]

//>> CLEAR_[DLP_FIR_REG_0_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_SL_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_SL_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_SL_ECC_UE]

//>> GET_[DLP_FIR_REG_0_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_SL_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_SL_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SL_ECC_UE]

//>> GET_[DLP_FIR_REG_0_SL_ECC_UE]
static inline bool GET_DLP_FIR_REG_0_SL_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_SL_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SL_ECC_UE]

//>> SET_[DLP_FIR_REG_1_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SL_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SL_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SL_ECC_UE]

//>> SET_[DLP_FIR_REG_1_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SL_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SL_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SL_ECC_UE]

//>> SET_[DLP_FIR_REG_1_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SL_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_SL_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SL_ECC_UE]

//>> CLEAR_[DLP_FIR_REG_1_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_SL_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_SL_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_SL_ECC_UE]

//>> GET_[DLP_FIR_REG_1_SL_ECC_UE]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_SL_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_SL_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SL_ECC_UE]

//>> GET_[DLP_FIR_REG_1_SL_ECC_UE]
static inline bool GET_DLP_FIR_REG_1_SL_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_SL_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_SL_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SL_ECC_UE]

//>> SET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_RETRAIN_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]

//>> SET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_RETRAIN_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_RETRAIN_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]

//>> SET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_RETRAIN_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]

//>> CLEAR_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_RETRAIN_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]

//>> GET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_RETRAIN_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]

//>> GET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]
static inline bool GET_DLP_FIR_REG_0_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_RETRAIN_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_RETRAIN_THRESHOLD]

//>> SET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_RETRAIN_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]

//>> SET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_RETRAIN_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_RETRAIN_THRESHOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]

//>> SET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_RETRAIN_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]

//>> CLEAR_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_RETRAIN_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]

//>> GET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_RETRAIN_THRESHOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]

//>> GET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]
static inline bool GET_DLP_FIR_REG_1_RETRAIN_THRESHOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_RETRAIN_THRESHOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_RETRAIN_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_RETRAIN_THRESHOLD]

//>> SET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_LOSS_BLOCK_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]

//>> SET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_LOSS_BLOCK_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_LOSS_BLOCK_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]

//>> SET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_LOSS_BLOCK_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]

//>> CLEAR_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_LOSS_BLOCK_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]

//>> GET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_LOSS_BLOCK_ALIGN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]

//>> GET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]
static inline bool GET_DLP_FIR_REG_0_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_LOSS_BLOCK_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_LOSS_BLOCK_ALIGN]

//>> SET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_LOSS_BLOCK_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]

//>> SET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_LOSS_BLOCK_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_LOSS_BLOCK_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]

//>> SET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_LOSS_BLOCK_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]

//>> CLEAR_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_LOSS_BLOCK_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]

//>> GET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_LOSS_BLOCK_ALIGN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]

//>> GET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]
static inline bool GET_DLP_FIR_REG_1_LOSS_BLOCK_ALIGN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_LOSS_BLOCK_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_LOSS_BLOCK_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_LOSS_BLOCK_ALIGN]

//>> SET_[DLP_FIR_REG_0_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_INVALID_BLOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_INVALID_BLOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_INVALID_BLOCK]

//>> SET_[DLP_FIR_REG_0_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_INVALID_BLOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_INVALID_BLOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_INVALID_BLOCK]

//>> SET_[DLP_FIR_REG_0_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_INVALID_BLOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_INVALID_BLOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_INVALID_BLOCK]

//>> CLEAR_[DLP_FIR_REG_0_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_INVALID_BLOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_INVALID_BLOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_INVALID_BLOCK]

//>> GET_[DLP_FIR_REG_0_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_INVALID_BLOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_INVALID_BLOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_INVALID_BLOCK]

//>> GET_[DLP_FIR_REG_0_INVALID_BLOCK]
static inline bool GET_DLP_FIR_REG_0_INVALID_BLOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_INVALID_BLOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_INVALID_BLOCK]

//>> SET_[DLP_FIR_REG_1_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_INVALID_BLOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_INVALID_BLOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_INVALID_BLOCK]

//>> SET_[DLP_FIR_REG_1_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_INVALID_BLOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_INVALID_BLOCK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_INVALID_BLOCK]

//>> SET_[DLP_FIR_REG_1_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_INVALID_BLOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_INVALID_BLOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_INVALID_BLOCK]

//>> CLEAR_[DLP_FIR_REG_1_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_INVALID_BLOCK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_INVALID_BLOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_INVALID_BLOCK]

//>> GET_[DLP_FIR_REG_1_INVALID_BLOCK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_INVALID_BLOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_INVALID_BLOCK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_INVALID_BLOCK]

//>> GET_[DLP_FIR_REG_1_INVALID_BLOCK]
static inline bool GET_DLP_FIR_REG_1_INVALID_BLOCK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_INVALID_BLOCK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_INVALID_BLOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_INVALID_BLOCK]

//>> SET_[DLP_FIR_REG_0_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_DESKEW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_DESKEW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_DESKEW_ERROR]

//>> SET_[DLP_FIR_REG_0_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_DESKEW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_DESKEW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_DESKEW_ERROR]

//>> SET_[DLP_FIR_REG_0_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_DESKEW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_DESKEW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_DESKEW_ERROR]

//>> CLEAR_[DLP_FIR_REG_0_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_DESKEW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_DESKEW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_DESKEW_ERROR]

//>> GET_[DLP_FIR_REG_0_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_DESKEW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_DESKEW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_DESKEW_ERROR]

//>> GET_[DLP_FIR_REG_0_DESKEW_ERROR]
static inline bool GET_DLP_FIR_REG_0_DESKEW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_DESKEW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_DESKEW_ERROR]

//>> SET_[DLP_FIR_REG_1_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_DESKEW_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_DESKEW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_DESKEW_ERROR]

//>> SET_[DLP_FIR_REG_1_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_DESKEW_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_DESKEW_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_DESKEW_ERROR]

//>> SET_[DLP_FIR_REG_1_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_DESKEW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_DESKEW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_DESKEW_ERROR]

//>> CLEAR_[DLP_FIR_REG_1_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_DESKEW_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_DESKEW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_DESKEW_ERROR]

//>> GET_[DLP_FIR_REG_1_DESKEW_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_DESKEW_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_DESKEW_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_DESKEW_ERROR]

//>> GET_[DLP_FIR_REG_1_DESKEW_ERROR]
static inline bool GET_DLP_FIR_REG_1_DESKEW_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_DESKEW_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_DESKEW_ERROR]

//>> SET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_DESKEW_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]

//>> SET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_DESKEW_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_DESKEW_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]

//>> SET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_DESKEW_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]

//>> CLEAR_[DLP_FIR_REG_0_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_DESKEW_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_DESKEW_OVERFLOW]

//>> GET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_DESKEW_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]

//>> GET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]
static inline bool GET_DLP_FIR_REG_0_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_DESKEW_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_DESKEW_OVERFLOW]

//>> SET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_DESKEW_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]

//>> SET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_DESKEW_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_DESKEW_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]

//>> SET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_DESKEW_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]

//>> CLEAR_[DLP_FIR_REG_1_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_DESKEW_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_DESKEW_OVERFLOW]

//>> GET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_DESKEW_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]

//>> GET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]
static inline bool GET_DLP_FIR_REG_1_DESKEW_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_DESKEW_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_DESKEW_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_DESKEW_OVERFLOW]

//>> SET_[DLP_FIR_REG_0_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SW_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SW_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SW_RETRAIN]

//>> SET_[DLP_FIR_REG_0_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SW_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SW_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SW_RETRAIN]

//>> SET_[DLP_FIR_REG_0_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SW_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_SW_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SW_RETRAIN]

//>> CLEAR_[DLP_FIR_REG_0_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_SW_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_SW_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_SW_RETRAIN]

//>> GET_[DLP_FIR_REG_0_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_SW_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_SW_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SW_RETRAIN]

//>> GET_[DLP_FIR_REG_0_SW_RETRAIN]
static inline bool GET_DLP_FIR_REG_0_SW_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_SW_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SW_RETRAIN]

//>> SET_[DLP_FIR_REG_1_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SW_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SW_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SW_RETRAIN]

//>> SET_[DLP_FIR_REG_1_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SW_RETRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SW_RETRAIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SW_RETRAIN]

//>> SET_[DLP_FIR_REG_1_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SW_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_SW_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SW_RETRAIN]

//>> CLEAR_[DLP_FIR_REG_1_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_SW_RETRAIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_SW_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_SW_RETRAIN]

//>> GET_[DLP_FIR_REG_1_SW_RETRAIN]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_SW_RETRAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_SW_RETRAIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SW_RETRAIN]

//>> GET_[DLP_FIR_REG_1_SW_RETRAIN]
static inline bool GET_DLP_FIR_REG_1_SW_RETRAIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_SW_RETRAIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_SW_RETRAIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SW_RETRAIN]

//>> SET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]

//>> SET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]

//>> SET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]

//>> CLEAR_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]

//>> GET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]

//>> GET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]
static inline bool GET_DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW]

//>> SET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]

//>> SET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]

//>> SET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]

//>> CLEAR_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]

//>> GET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]

//>> GET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]
static inline bool GET_DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW]

//>> SET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]

//>> SET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]

//>> SET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]

//>> CLEAR_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]

//>> GET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]

//>> GET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]
static inline bool GET_DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW]

//>> SET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]

//>> SET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]

//>> SET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]

//>> CLEAR_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]

//>> GET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]

//>> GET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]
static inline bool GET_DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW]

//>> SET_[DLP_FIR_REG_0_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NUM_REPLAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_NUM_REPLAY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NUM_REPLAY]

//>> SET_[DLP_FIR_REG_0_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NUM_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_NUM_REPLAY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NUM_REPLAY]

//>> SET_[DLP_FIR_REG_0_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NUM_REPLAY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_NUM_REPLAY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NUM_REPLAY]

//>> CLEAR_[DLP_FIR_REG_0_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_NUM_REPLAY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_NUM_REPLAY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_NUM_REPLAY]

//>> GET_[DLP_FIR_REG_0_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_NUM_REPLAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_NUM_REPLAY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_NUM_REPLAY]

//>> GET_[DLP_FIR_REG_0_NUM_REPLAY]
static inline bool GET_DLP_FIR_REG_0_NUM_REPLAY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_NUM_REPLAY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_NUM_REPLAY]

//>> SET_[DLP_FIR_REG_1_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NUM_REPLAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_NUM_REPLAY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NUM_REPLAY]

//>> SET_[DLP_FIR_REG_1_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NUM_REPLAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_NUM_REPLAY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NUM_REPLAY]

//>> SET_[DLP_FIR_REG_1_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NUM_REPLAY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_NUM_REPLAY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NUM_REPLAY]

//>> CLEAR_[DLP_FIR_REG_1_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_NUM_REPLAY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_NUM_REPLAY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_NUM_REPLAY]

//>> GET_[DLP_FIR_REG_1_NUM_REPLAY]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_NUM_REPLAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_NUM_REPLAY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_NUM_REPLAY]

//>> GET_[DLP_FIR_REG_1_NUM_REPLAY]
static inline bool GET_DLP_FIR_REG_1_NUM_REPLAY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_NUM_REPLAY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_NUM_REPLAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_NUM_REPLAY]

//>> SET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TRAINING_SET_RECEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]

//>> SET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TRAINING_SET_RECEIVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TRAINING_SET_RECEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]

//>> SET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_TRAINING_SET_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]

//>> CLEAR_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_TRAINING_SET_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]

//>> GET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_TRAINING_SET_RECEIVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]

//>> GET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]
static inline bool GET_DLP_FIR_REG_0_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_TRAINING_SET_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TRAINING_SET_RECEIVED]

//>> SET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TRAINING_SET_RECEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]

//>> SET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TRAINING_SET_RECEIVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TRAINING_SET_RECEIVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]

//>> SET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_TRAINING_SET_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]

//>> CLEAR_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_TRAINING_SET_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]

//>> GET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_TRAINING_SET_RECEIVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]

//>> GET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]
static inline bool GET_DLP_FIR_REG_1_TRAINING_SET_RECEIVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_TRAINING_SET_RECEIVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_SET_RECEIVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TRAINING_SET_RECEIVED]

//>> SET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_PRBS_SELECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]

//>> SET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_PRBS_SELECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_PRBS_SELECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]

//>> SET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_PRBS_SELECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]

//>> CLEAR_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_PRBS_SELECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]

//>> GET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_PRBS_SELECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]

//>> GET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]
static inline bool GET_DLP_FIR_REG_0_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_PRBS_SELECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_PRBS_SELECT_ERROR]

//>> SET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_PRBS_SELECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]

//>> SET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_PRBS_SELECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_PRBS_SELECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]

//>> SET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_PRBS_SELECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]

//>> CLEAR_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_PRBS_SELECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]

//>> GET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_PRBS_SELECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]

//>> GET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]
static inline bool GET_DLP_FIR_REG_1_PRBS_SELECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_PRBS_SELECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_PRBS_SELECT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_PRBS_SELECT_ERROR]

//>> SET_[DLP_FIR_REG_0_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TCOMPLETE_BAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TCOMPLETE_BAD]

//>> SET_[DLP_FIR_REG_0_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TCOMPLETE_BAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TCOMPLETE_BAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TCOMPLETE_BAD]

//>> SET_[DLP_FIR_REG_0_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_TCOMPLETE_BAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TCOMPLETE_BAD]

//>> CLEAR_[DLP_FIR_REG_0_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_TCOMPLETE_BAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_TCOMPLETE_BAD]

//>> GET_[DLP_FIR_REG_0_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_TCOMPLETE_BAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TCOMPLETE_BAD]

//>> GET_[DLP_FIR_REG_0_TCOMPLETE_BAD]
static inline bool GET_DLP_FIR_REG_0_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_TCOMPLETE_BAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TCOMPLETE_BAD]

//>> SET_[DLP_FIR_REG_1_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TCOMPLETE_BAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TCOMPLETE_BAD]

//>> SET_[DLP_FIR_REG_1_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TCOMPLETE_BAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TCOMPLETE_BAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TCOMPLETE_BAD]

//>> SET_[DLP_FIR_REG_1_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_TCOMPLETE_BAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TCOMPLETE_BAD]

//>> CLEAR_[DLP_FIR_REG_1_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_TCOMPLETE_BAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_TCOMPLETE_BAD]

//>> GET_[DLP_FIR_REG_1_TCOMPLETE_BAD]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_TCOMPLETE_BAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TCOMPLETE_BAD]

//>> GET_[DLP_FIR_REG_1_TCOMPLETE_BAD]
static inline bool GET_DLP_FIR_REG_1_TCOMPLETE_BAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_TCOMPLETE_BAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_TCOMPLETE_BAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TCOMPLETE_BAD]

//>> SET_[DLP_FIR_REG_0_NO_SPARE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NO_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_NO_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NO_SPARE]

//>> SET_[DLP_FIR_REG_0_NO_SPARE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NO_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_NO_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NO_SPARE]

//>> SET_[DLP_FIR_REG_0_NO_SPARE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NO_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_NO_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NO_SPARE]

//>> CLEAR_[DLP_FIR_REG_0_NO_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_NO_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_NO_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_NO_SPARE]

//>> GET_[DLP_FIR_REG_0_NO_SPARE]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_NO_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_NO_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_NO_SPARE]

//>> GET_[DLP_FIR_REG_0_NO_SPARE]
static inline bool GET_DLP_FIR_REG_0_NO_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_NO_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_NO_SPARE]

//>> SET_[DLP_FIR_REG_1_NO_SPARE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NO_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_NO_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NO_SPARE]

//>> SET_[DLP_FIR_REG_1_NO_SPARE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NO_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_NO_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NO_SPARE]

//>> SET_[DLP_FIR_REG_1_NO_SPARE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NO_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_NO_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NO_SPARE]

//>> CLEAR_[DLP_FIR_REG_1_NO_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_NO_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_NO_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_NO_SPARE]

//>> GET_[DLP_FIR_REG_1_NO_SPARE]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_NO_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_NO_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_NO_SPARE]

//>> GET_[DLP_FIR_REG_1_NO_SPARE]
static inline bool GET_DLP_FIR_REG_1_NO_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_NO_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_NO_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_NO_SPARE]

//>> SET_[DLP_FIR_REG_0_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SPARE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SPARE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SPARE_DONE]

//>> SET_[DLP_FIR_REG_0_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SPARE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_SPARE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SPARE_DONE]

//>> SET_[DLP_FIR_REG_0_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_SPARE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_SPARE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_SPARE_DONE]

//>> CLEAR_[DLP_FIR_REG_0_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_SPARE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_SPARE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_SPARE_DONE]

//>> GET_[DLP_FIR_REG_0_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_SPARE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_SPARE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SPARE_DONE]

//>> GET_[DLP_FIR_REG_0_SPARE_DONE]
static inline bool GET_DLP_FIR_REG_0_SPARE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_SPARE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_SPARE_DONE]

//>> SET_[DLP_FIR_REG_1_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SPARE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SPARE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SPARE_DONE]

//>> SET_[DLP_FIR_REG_1_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SPARE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_SPARE_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SPARE_DONE]

//>> SET_[DLP_FIR_REG_1_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_SPARE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_SPARE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_SPARE_DONE]

//>> CLEAR_[DLP_FIR_REG_1_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_SPARE_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_SPARE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_SPARE_DONE]

//>> GET_[DLP_FIR_REG_1_SPARE_DONE]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_SPARE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_SPARE_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SPARE_DONE]

//>> GET_[DLP_FIR_REG_1_SPARE_DONE]
static inline bool GET_DLP_FIR_REG_1_SPARE_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_SPARE_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_SPARE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_SPARE_DONE]

//>> SET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]

//>> SET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]

//>> SET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]

//>> CLEAR_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]

//>> GET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]

//>> GET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]
static inline bool GET_DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS]

//>> SET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]

//>> SET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]

//>> SET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]

//>> CLEAR_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]

//>> GET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]

//>> GET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]
static inline bool GET_DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS]

//>> SET_[DLP_FIR_REG_0_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_NPU_DLX_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NPU_DLX_ERROR]

//>> SET_[DLP_FIR_REG_0_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NPU_DLX_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_NPU_DLX_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NPU_DLX_ERROR]

//>> SET_[DLP_FIR_REG_0_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_NPU_DLX_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_NPU_DLX_ERROR]

//>> CLEAR_[DLP_FIR_REG_0_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_NPU_DLX_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_NPU_DLX_ERROR]

//>> GET_[DLP_FIR_REG_0_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_NPU_DLX_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_NPU_DLX_ERROR]

//>> GET_[DLP_FIR_REG_0_NPU_DLX_ERROR]
static inline bool GET_DLP_FIR_REG_0_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_NPU_DLX_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_NPU_DLX_ERROR]

//>> SET_[DLP_FIR_REG_1_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_NPU_DLX_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NPU_DLX_ERROR]

//>> SET_[DLP_FIR_REG_1_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NPU_DLX_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_NPU_DLX_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NPU_DLX_ERROR]

//>> SET_[DLP_FIR_REG_1_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_NPU_DLX_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_NPU_DLX_ERROR]

//>> CLEAR_[DLP_FIR_REG_1_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_NPU_DLX_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_NPU_DLX_ERROR]

//>> GET_[DLP_FIR_REG_1_NPU_DLX_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_NPU_DLX_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_NPU_DLX_ERROR]

//>> GET_[DLP_FIR_REG_1_NPU_DLX_ERROR]
static inline bool GET_DLP_FIR_REG_1_NPU_DLX_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_NPU_DLX_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_NPU_DLX_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_NPU_DLX_ERROR]

//>> SET_[DLP_FIR_REG_0_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_OSC_SWITCH]

//>> SET_[DLP_FIR_REG_0_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_OSC_SWITCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_OSC_SWITCH]

//>> SET_[DLP_FIR_REG_0_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_OSC_SWITCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_OSC_SWITCH]

//>> CLEAR_[DLP_FIR_REG_0_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_OSC_SWITCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_OSC_SWITCH]

//>> GET_[DLP_FIR_REG_0_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_OSC_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_OSC_SWITCH]

//>> GET_[DLP_FIR_REG_0_OSC_SWITCH]
static inline bool GET_DLP_FIR_REG_0_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_OSC_SWITCH]

//>> SET_[DLP_FIR_REG_1_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_OSC_SWITCH]

//>> SET_[DLP_FIR_REG_1_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_OSC_SWITCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_OSC_SWITCH]

//>> SET_[DLP_FIR_REG_1_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_OSC_SWITCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_OSC_SWITCH]

//>> CLEAR_[DLP_FIR_REG_1_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_OSC_SWITCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_OSC_SWITCH]

//>> GET_[DLP_FIR_REG_1_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_OSC_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_OSC_SWITCH]

//>> GET_[DLP_FIR_REG_1_OSC_SWITCH]
static inline bool GET_DLP_FIR_REG_1_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_OSC_SWITCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_OSC_SWITCH]

//>> SET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]

//>> CLEAR_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]

//>> GET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]

//>> GET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]
static inline bool GET_DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]

//>> CLEAR_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]

//>> GET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]

//>> GET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]
static inline bool GET_DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]

//>> CLEAR_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]

//>> GET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]

//>> GET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]
static inline bool GET_DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]

//>> CLEAR_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]

//>> GET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]

//>> GET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]
static inline bool GET_DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR]

//>> SET_[DLP_FIR_REG_0_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TRAINING_FAILED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TRAINING_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TRAINING_FAILED]

//>> SET_[DLP_FIR_REG_0_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TRAINING_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_TRAINING_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TRAINING_FAILED]

//>> SET_[DLP_FIR_REG_0_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_TRAINING_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_TRAINING_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_TRAINING_FAILED]

//>> CLEAR_[DLP_FIR_REG_0_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_TRAINING_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_TRAINING_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_TRAINING_FAILED]

//>> GET_[DLP_FIR_REG_0_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_TRAINING_FAILED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_TRAINING_FAILED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TRAINING_FAILED]

//>> GET_[DLP_FIR_REG_0_TRAINING_FAILED]
static inline bool GET_DLP_FIR_REG_0_TRAINING_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_TRAINING_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_TRAINING_FAILED]

//>> SET_[DLP_FIR_REG_1_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TRAINING_FAILED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TRAINING_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TRAINING_FAILED]

//>> SET_[DLP_FIR_REG_1_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TRAINING_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_TRAINING_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TRAINING_FAILED]

//>> SET_[DLP_FIR_REG_1_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_TRAINING_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_TRAINING_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_TRAINING_FAILED]

//>> CLEAR_[DLP_FIR_REG_1_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_TRAINING_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_TRAINING_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_TRAINING_FAILED]

//>> GET_[DLP_FIR_REG_1_TRAINING_FAILED]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_TRAINING_FAILED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_TRAINING_FAILED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TRAINING_FAILED]

//>> GET_[DLP_FIR_REG_1_TRAINING_FAILED]
static inline bool GET_DLP_FIR_REG_1_TRAINING_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_TRAINING_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_TRAINING_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_TRAINING_FAILED]

//>> SET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_UNRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]

//>> SET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_UNRECOVERABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_UNRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]

//>> SET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_UNRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]

//>> CLEAR_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_UNRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]

//>> GET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_UNRECOVERABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]

//>> GET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]
static inline bool GET_DLP_FIR_REG_0_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_UNRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_UNRECOVERABLE_ERROR]

//>> SET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_UNRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]

//>> SET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_UNRECOVERABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_UNRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]

//>> SET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_UNRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]

//>> CLEAR_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_UNRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]

//>> GET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_UNRECOVERABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]

//>> GET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]
static inline bool GET_DLP_FIR_REG_1_UNRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_UNRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_UNRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_UNRECOVERABLE_ERROR]

//>> SET_[DLP_FIR_REG_0_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_0_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_INTERNAL_ERROR]

//>> SET_[DLP_FIR_REG_0_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_INTERNAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_0_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_0_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_INTERNAL_ERROR]

//>> SET_[DLP_FIR_REG_0_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_0_INTERNAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_0_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_0_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_0_INTERNAL_ERROR]

//>> CLEAR_[DLP_FIR_REG_0_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_0_INTERNAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_0_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_0_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_0_INTERNAL_ERROR]

//>> GET_[DLP_FIR_REG_0_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_0_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_0_INTERNAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_0_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_INTERNAL_ERROR]

//>> GET_[DLP_FIR_REG_0_INTERNAL_ERROR]
static inline bool GET_DLP_FIR_REG_0_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_0_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_0_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_0_INTERNAL_ERROR]

//>> SET_[DLP_FIR_REG_1_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_REG_1_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_INTERNAL_ERROR]

//>> SET_[DLP_FIR_REG_1_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_INTERNAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_REG_1_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_REG_1_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_INTERNAL_ERROR]

//>> SET_[DLP_FIR_REG_1_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_REG_1_INTERNAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_REG_1_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_REG_1_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_REG_1_INTERNAL_ERROR]

//>> CLEAR_[DLP_FIR_REG_1_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_REG_1_INTERNAL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_REG_1_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_REG_1_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_REG_1_INTERNAL_ERROR]

//>> GET_[DLP_FIR_REG_1_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_REG_1_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_REG_1_INTERNAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_REG_1_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_INTERNAL_ERROR]

//>> GET_[DLP_FIR_REG_1_INTERNAL_ERROR]
static inline bool GET_DLP_FIR_REG_1_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_REG_RW, DLP_FIR_REG_WO_AND, DLP_FIR_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_REG_1_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_REG_1_INTERNAL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_REG_1_INTERNAL_ERROR]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
