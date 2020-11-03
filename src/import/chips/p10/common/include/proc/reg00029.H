/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00029.H $         */
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

#ifndef __PROC_REG00029_H_
#define __PROC_REG00029_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PULL_READ_UNDERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_PUSH_WRITE_OVERFLOW_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_STREAM_TYPE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_TIMEOUT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_READ_DATA_PARITY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_OCI_SLAVE_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_ADDR_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_OCB_PIB_DATA_PARITY_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE_3]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_SPARE2]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3_OCB_PIB_OCBDR3_DATA]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR,
           TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0_OCB_PIB_OCBESR0_ERROR_ADDR]

//>> PREP_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_SRAM_CTL_SRBV0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0]

//>> GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_SRAM_CTL_SRBV0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0]

//>> PUT_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_SRAM_CTL_SRBV0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_SRAM_CTL_SRBV0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0]


//>> SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0]

//>> SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0]

//>> GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_SRAM_CTL_SRBV0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0,
           TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_SRAM_CTL_SRBV0_SRAM_SRBV0_BOOT_VECTOR_WORD0]

//>> PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR]

//>> PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR]


//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_IR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR]

//>> SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR]

//>> GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR,
           TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_TR_HIST_FSI_BYTE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
