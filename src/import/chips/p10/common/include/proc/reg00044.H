/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00044.H $         */
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

#ifndef __PROC_REG00044_H_
#define __PROC_REG00044_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]

//>> PUT_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> PREP_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
