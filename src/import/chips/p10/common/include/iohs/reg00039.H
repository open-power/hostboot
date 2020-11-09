/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00039.H $         */
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

#ifndef __IOHS_REG00039_H_
#define __IOHS_REG00039_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> PREP_[DLP_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_FIR_MASK_REG_RW]

//>> GET_[DLP_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, DLP_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_RW]

//>> PUT_[DLP_FIR_MASK_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, DLP_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_FIR_MASK_REG_RW]

//>> PREP_[DLP_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_FIR_MASK_REG_WO_AND]

//>> GET_[DLP_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, DLP_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_WO_AND]

//>> PUT_[DLP_FIR_MASK_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, DLP_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_FIR_MASK_REG_WO_AND]

//>> PREP_[DLP_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_FIR_MASK_REG_WO_OR]

//>> GET_[DLP_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, DLP_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_WO_OR]

//>> PUT_[DLP_FIR_MASK_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, DLP_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_FIR_MASK_REG_WO_OR]


//>> SET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TRAINED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_TRAINED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_TRAINED_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TRAINED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TRAINED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_TRAINED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_TRAINED_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINED_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TRAINED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_OP_IRQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_OP_IRQ_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_OP_IRQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_OP_IRQ_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_OP_IRQ_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_OP_IRQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_OP_IRQ_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_OP_IRQ_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_OP_IRQ_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_OP_IRQ_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_OP_IRQ_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OP_IRQ_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_OP_IRQ_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_CRC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_CRC_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_CRC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_CRC_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_CRC_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_CRC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_CRC_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_CRC_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_CRC_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_CRC_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_CRC_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CRC_ERROR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_CRC_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_NO_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NO_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_NO_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_NO_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_NO_SPARE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_NO_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NO_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_NO_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_NO_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_NO_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_NO_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NO_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_NO_SPARE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SPARE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SPARE_DONE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_SPARE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_SPARE_DONE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_SPARE_DONE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SPARE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SPARE_DONE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_SPARE_DONE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_SPARE_DONE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_SPARE_DONE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_SPARE_DONE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_SPARE_DONE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_SPARE_DONE_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]

//>> SET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& SET_DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]

//>> CLEAR_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]
static inline fapi2::buffer<uint64_t>& GET_DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]

//>> GET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]
static inline bool GET_DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_FIR_MASK_REG_RW, DLP_FIR_MASK_REG_WO_AND, DLP_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK]

//>> PREP_[DLP_LINK1_ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK1_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_ERROR_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK1_ERROR_STATUS]

//>> GET_[DLP_LINK1_ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK1_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_ERROR_STATUS;
#endif
    return fapi2::getScom(i_target, DLP_LINK1_ERROR_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK1_ERROR_STATUS]

//>> PUT_[DLP_LINK1_ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK1_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return fapi2::putScom(i_target, DLP_LINK1_ERROR_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK1_ERROR_STATUS]


//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]

//>> CLEAR_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]

//>> GET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]

//>> GET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]
static inline bool GET_DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RESET_KEEPER]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE]

//>> GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_CE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_DATA]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_DATA]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE]

//>> GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_FRAME_UE_CTL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_UE_CTL]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC]

//>> GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_OPT_OSC_SWITCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_OPT_OSC_SWITCH]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN]

//>> GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_INIT_SEQ_DOWN]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_TSTART_GIVEUP]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_LANE_MISMATCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_MISMATCH]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_SLOWER]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV]

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV]

//>> GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV,
           DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_SEQ_LINK_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_CRC_COUNT_FAIL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_LINK_PAIR_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UNRECOV]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_INTERNAL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_UE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_REMOTE_SW_DISABLE]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_REPLAY_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_TL_RL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_DLX_RL_ERROR]

//>> SET_[DLP_LINK1_ERROR_STATUS_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_INTERNAL,
           DLP_LINK1_ERROR_STATUS_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_INTERNAL]

//>> SET_[DLP_LINK1_ERROR_STATUS_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_INTERNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<DLP_LINK1_ERROR_STATUS_INTERNAL,
           DLP_LINK1_ERROR_STATUS_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_ERROR_STATUS_INTERNAL]

//>> GET_[DLP_LINK1_ERROR_STATUS_INTERNAL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<DLP_LINK1_ERROR_STATUS_INTERNAL,
           DLP_LINK1_ERROR_STATUS_INTERNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_ERROR_STATUS_INTERNAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_ERROR_STATUS_INTERNAL]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_DATA_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ODL_CTL_PARTIY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_PACKET_STATE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_T1_TRANSMIT_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_INVALID_STATE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_DATA_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RX_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_TX_DATA_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_SHIFT_AMOUNT_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_LINK_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_PROTOCOL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_ACK_FIFO_UNDERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_FRAME_CTL_PARITY_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECAL_INVALID_STATE_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.insertFromRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.setBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return o_data.clearBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.extractToRight<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]
static inline bool GET_P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_ERROR_STATUS));
#endif
    return i_data.getBit<P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_DLP_LINK1_ERROR_STATUS_RECEIVE_CONTROL_ERROR]

//>> PREP_[DLP_LINK1_TX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_LINK1_TX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_TX_LANE_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_LINK1_TX_LANE_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_LINK1_TX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_LINK1_TX_LANE_CONTROL;
#endif
    return fapi2::getScom(i_target, DLP_LINK1_TX_LANE_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL]

//>> PUT_[DLP_LINK1_TX_LANE_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_LINK1_TX_LANE_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return fapi2::putScom(i_target, DLP_LINK1_TX_LANE_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_LINK1_TX_LANE_CONTROL]


//>> SET_[DLP_LINK1_TX_LANE_CONTROL_00_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_00_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_00_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_00_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_00_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_00_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_00_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_00_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_00_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_00_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_00_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_00_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_00_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_00_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_00_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_00_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_00_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_00_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_01_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_01_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_01_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_01_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_01_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_01_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_01_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_01_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_01_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_01_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_01_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_01_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_01_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_01_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_01_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_01_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_01_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_01_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_02_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_02_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_02_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_02_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_02_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_02_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_02_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_02_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_02_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_02_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_02_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_02_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_02_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_02_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_02_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_02_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_02_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_02_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_03_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_03_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_03_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_03_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_03_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_03_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_03_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_03_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_03_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_03_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_03_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_03_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_03_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_03_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_03_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_03_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_03_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_03_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_04_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_04_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_04_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_04_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_04_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_04_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_04_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_04_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_04_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_04_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_04_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_04_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_04_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_04_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_04_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_04_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_04_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_04_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_05_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_05_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_05_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_05_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_05_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_05_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_05_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_05_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_05_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_05_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_05_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_05_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_05_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_05_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_05_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_05_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_05_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_05_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_06_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_06_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_06_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_06_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_06_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_06_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_06_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_06_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_06_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_06_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_06_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_06_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_06_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_06_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_06_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_06_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_06_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_06_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_07_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_07_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_07_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_07_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_07_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_07_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_07_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_07_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_07_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_07_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_07_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_07_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_07_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_07_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_07_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_07_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_07_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_07_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL,
           DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_FAILED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_FAILED,
           DLP_LINK1_TX_LANE_CONTROL_FAILED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_FAILED]

//>> SET_[DLP_LINK1_TX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_TX_LANE_CONTROL_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return o_data.insertFromRight<DLP_LINK1_TX_LANE_CONTROL_FAILED,
           DLP_LINK1_TX_LANE_CONTROL_FAILED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_LINK1_TX_LANE_CONTROL_FAILED]

//>> GET_[DLP_LINK1_TX_LANE_CONTROL_FAILED]
static inline fapi2::buffer<uint64_t>& GET_DLP_LINK1_TX_LANE_CONTROL_FAILED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_LINK1_TX_LANE_CONTROL));
#endif
    return i_data.extractToRight<DLP_LINK1_TX_LANE_CONTROL_FAILED,
           DLP_LINK1_TX_LANE_CONTROL_FAILED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_LINK1_TX_LANE_CONTROL_FAILED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_LINK1_TX_LANE_CONTROL_FAILED]

//>> PREP_[DLP_SEC_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_DLP_SEC_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_SEC_CONFIG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[DLP_SEC_CONFIG]

//>> GET_[DLP_SEC_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_DLP_SEC_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = DLP_SEC_CONFIG;
#endif
    return fapi2::getScom(i_target, DLP_SEC_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[DLP_SEC_CONFIG]

//>> PUT_[DLP_SEC_CONFIG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_DLP_SEC_CONFIG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return fapi2::putScom(i_target, DLP_SEC_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[DLP_SEC_CONFIG]


//>> SET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_ENABLE_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_ENABLE_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]

//>> SET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_ENABLE_ERR_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_ENABLE_ERR_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]

//>> SET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_ENABLE_ERR_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.setBit<DLP_SEC_CONFIG_ENABLE_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]

//>> CLEAR_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_SEC_CONFIG_ENABLE_ERR_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.clearBit<DLP_SEC_CONFIG_ENABLE_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]

//>> GET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_ENABLE_ERR_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_ENABLE_ERR_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]

//>> GET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]
static inline bool GET_DLP_SEC_CONFIG_ENABLE_ERR_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.getBit<DLP_SEC_CONFIG_ENABLE_ERR_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_ERR_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_ENABLE_ERR_INJ]

//>> SET_[DLP_SEC_CONFIG_ENABLE_TRACE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_ENABLE_TRACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_ENABLE_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_ENABLE_TRACE]

//>> SET_[DLP_SEC_CONFIG_ENABLE_TRACE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_ENABLE_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_ENABLE_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_ENABLE_TRACE]

//>> SET_[DLP_SEC_CONFIG_ENABLE_TRACE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_ENABLE_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.setBit<DLP_SEC_CONFIG_ENABLE_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_ENABLE_TRACE]

//>> CLEAR_[DLP_SEC_CONFIG_ENABLE_TRACE]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_SEC_CONFIG_ENABLE_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.clearBit<DLP_SEC_CONFIG_ENABLE_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_SEC_CONFIG_ENABLE_TRACE]

//>> GET_[DLP_SEC_CONFIG_ENABLE_TRACE]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_ENABLE_TRACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_ENABLE_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_ENABLE_TRACE]

//>> GET_[DLP_SEC_CONFIG_ENABLE_TRACE]
static inline bool GET_DLP_SEC_CONFIG_ENABLE_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.getBit<DLP_SEC_CONFIG_ENABLE_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_SEC_CONFIG_ENABLE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_ENABLE_TRACE]

//>> SET_[DLP_SEC_CONFIG_RESET_INJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_RESET_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_RESET_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_RESET_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_RESET_INJ]

//>> SET_[DLP_SEC_CONFIG_RESET_INJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_RESET_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_RESET_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_RESET_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_RESET_INJ]

//>> SET_[DLP_SEC_CONFIG_RESET_INJ]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_RESET_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.setBit<DLP_SEC_CONFIG_RESET_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_iohs Invalid dial access DLP_SEC_CONFIG_RESET_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_RESET_INJ]

//>> CLEAR_[DLP_SEC_CONFIG_RESET_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_DLP_SEC_CONFIG_RESET_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.clearBit<DLP_SEC_CONFIG_RESET_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_iohs Invalid dial access DLP_SEC_CONFIG_RESET_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[DLP_SEC_CONFIG_RESET_INJ]

//>> GET_[DLP_SEC_CONFIG_RESET_INJ]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_RESET_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_RESET_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_RESET_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_RESET_INJ]

//>> GET_[DLP_SEC_CONFIG_RESET_INJ]
static inline bool GET_DLP_SEC_CONFIG_RESET_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.getBit<DLP_SEC_CONFIG_RESET_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_iohs Invalid dial access DLP_SEC_CONFIG_RESET_INJ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_RESET_INJ]

//>> SET_[DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE,
           DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE]

//>> SET_[DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE,
           DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE]

//>> GET_[DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE,
           DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE]

//>> SET_[DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE,
           DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE]

//>> SET_[DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE,
           DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE]

//>> GET_[DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE,
           DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE]

//>> SET_[DLP_SEC_CONFIG_SBE_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_SBE_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_SBE_ERROR_RATE,
           DLP_SEC_CONFIG_SBE_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_SBE_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_SBE_ERROR_RATE]

//>> SET_[DLP_SEC_CONFIG_SBE_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_SBE_ERROR_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_SBE_ERROR_RATE,
           DLP_SEC_CONFIG_SBE_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_SBE_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_SBE_ERROR_RATE]

//>> GET_[DLP_SEC_CONFIG_SBE_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_SBE_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_SBE_ERROR_RATE,
           DLP_SEC_CONFIG_SBE_ERROR_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_SBE_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_SBE_ERROR_RATE]

//>> SET_[DLP_SEC_CONFIG_RAND_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_RAND_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_RAND_ERROR_RATE,
           DLP_SEC_CONFIG_RAND_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_RAND_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_RAND_ERROR_RATE]

//>> SET_[DLP_SEC_CONFIG_RAND_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_RAND_ERROR_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_RAND_ERROR_RATE,
           DLP_SEC_CONFIG_RAND_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_RAND_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_RAND_ERROR_RATE]

//>> GET_[DLP_SEC_CONFIG_RAND_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_RAND_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_RAND_ERROR_RATE,
           DLP_SEC_CONFIG_RAND_ERROR_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_RAND_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_RAND_ERROR_RATE]

//>> SET_[DLP_SEC_CONFIG_INV_SH_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_INV_SH_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_INV_SH_ERROR_RATE,
           DLP_SEC_CONFIG_INV_SH_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_INV_SH_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_INV_SH_ERROR_RATE]

//>> SET_[DLP_SEC_CONFIG_INV_SH_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_INV_SH_ERROR_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_INV_SH_ERROR_RATE,
           DLP_SEC_CONFIG_INV_SH_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_INV_SH_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_INV_SH_ERROR_RATE]

//>> GET_[DLP_SEC_CONFIG_INV_SH_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_INV_SH_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_INV_SH_ERROR_RATE,
           DLP_SEC_CONFIG_INV_SH_ERROR_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_INV_SH_ERROR_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_INV_SH_ERROR_RATE]

//>> SET_[DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE,
           DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE]

//>> SET_[DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE,
           DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE]

//>> GET_[DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE,
           DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE]

//>> SET_[DLP_SEC_CONFIG_EDPL_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_EDPL_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_EDPL_RATE,
           DLP_SEC_CONFIG_EDPL_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_iohs Invalid dial access DLP_SEC_CONFIG_EDPL_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_EDPL_RATE]

//>> SET_[DLP_SEC_CONFIG_EDPL_RATE]
static inline fapi2::buffer<uint64_t>& SET_DLP_SEC_CONFIG_EDPL_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return o_data.insertFromRight<DLP_SEC_CONFIG_EDPL_RATE,
           DLP_SEC_CONFIG_EDPL_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_iohs Invalid dial access DLP_SEC_CONFIG_EDPL_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[DLP_SEC_CONFIG_EDPL_RATE]

//>> GET_[DLP_SEC_CONFIG_EDPL_RATE]
static inline fapi2::buffer<uint64_t>& GET_DLP_SEC_CONFIG_EDPL_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(DLP_SEC_CONFIG));
#endif
    return i_data.extractToRight<DLP_SEC_CONFIG_EDPL_RATE,
           DLP_SEC_CONFIG_EDPL_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_iohs Invalid dial access DLP_SEC_CONFIG_EDPL_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[DLP_SEC_CONFIG_EDPL_RATE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
