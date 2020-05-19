/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/iohs/reg00038.H $         */
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

#ifndef __IOHS_REG00038_H_
#define __IOHS_REG00038_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


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

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>> SET_[DLP_LINK1_ERROR_STATUS_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_DLP_LINK1_ERROR_STATUS_INTERNAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
