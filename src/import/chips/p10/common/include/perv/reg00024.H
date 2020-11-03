/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00024.H $         */
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

#ifndef __PERV_REG00024_H_
#define __PERV_REG00024_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[CPLT_CTRL2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL2_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL2_RW]

//>> GET_[CPLT_CTRL2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL2_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL2_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL2_RW]

//>> PUT_[CPLT_CTRL2_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL2_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL2_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL2_RW]

//>> PREP_[CPLT_CTRL2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL2_WO_CLEAR]

//>> GET_[CPLT_CTRL2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL2_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL2_WO_CLEAR]

//>> PUT_[CPLT_CTRL2_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL2_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL2_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL2_WO_CLEAR]

//>> PREP_[CPLT_CTRL2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL2_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL2_WO_OR]

//>> GET_[CPLT_CTRL2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL2_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL2_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL2_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL2_WO_OR]

//>> PUT_[CPLT_CTRL2_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL2_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL2_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL2_WO_OR]


//>> SET_[CPLT_CTRL2_0_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_0_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_0_PGOOD]

//>> SET_[CPLT_CTRL2_0_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_0_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_0_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_0_PGOOD]

//>> SET_[CPLT_CTRL2_0_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_0_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_0_PGOOD]

//>> CLEAR_[CPLT_CTRL2_0_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_0_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_0_PGOOD]

//>> GET_[CPLT_CTRL2_0_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_0_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_0_PGOOD]

//>> GET_[CPLT_CTRL2_0_PGOOD]
static inline bool GET_CPLT_CTRL2_0_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_0_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_0_PGOOD]

//>> SET_[CPLT_CTRL2_1_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_1_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_1_PGOOD]

//>> SET_[CPLT_CTRL2_1_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_1_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_1_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_1_PGOOD]

//>> SET_[CPLT_CTRL2_1_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_1_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_1_PGOOD]

//>> CLEAR_[CPLT_CTRL2_1_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_1_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_1_PGOOD]

//>> GET_[CPLT_CTRL2_1_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_1_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_1_PGOOD]

//>> GET_[CPLT_CTRL2_1_PGOOD]
static inline bool GET_CPLT_CTRL2_1_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_1_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_1_PGOOD]

//>> SET_[CPLT_CTRL2_2_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_2_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_2_PGOOD]

//>> SET_[CPLT_CTRL2_2_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_2_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_2_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_2_PGOOD]

//>> SET_[CPLT_CTRL2_2_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_2_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_2_PGOOD]

//>> CLEAR_[CPLT_CTRL2_2_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_2_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_2_PGOOD]

//>> GET_[CPLT_CTRL2_2_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_2_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_2_PGOOD]

//>> GET_[CPLT_CTRL2_2_PGOOD]
static inline bool GET_CPLT_CTRL2_2_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_2_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_2_PGOOD]

//>> SET_[CPLT_CTRL2_3_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_3_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_3_PGOOD]

//>> SET_[CPLT_CTRL2_3_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_3_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_3_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_3_PGOOD]

//>> SET_[CPLT_CTRL2_3_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_3_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_3_PGOOD]

//>> CLEAR_[CPLT_CTRL2_3_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_3_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_3_PGOOD]

//>> GET_[CPLT_CTRL2_3_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_3_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_3_PGOOD]

//>> GET_[CPLT_CTRL2_3_PGOOD]
static inline bool GET_CPLT_CTRL2_3_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_3_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_3_PGOOD]

//>> SET_[CPLT_CTRL2_4_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_4_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_4_PGOOD]

//>> SET_[CPLT_CTRL2_4_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_4_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_4_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_4_PGOOD]

//>> SET_[CPLT_CTRL2_4_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_4_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_4_PGOOD]

//>> CLEAR_[CPLT_CTRL2_4_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_4_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_4_PGOOD]

//>> GET_[CPLT_CTRL2_4_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_4_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_4_PGOOD]

//>> GET_[CPLT_CTRL2_4_PGOOD]
static inline bool GET_CPLT_CTRL2_4_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_4_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_4_PGOOD]

//>> SET_[CPLT_CTRL2_5_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_5_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_5_PGOOD]

//>> SET_[CPLT_CTRL2_5_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_5_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_5_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_5_PGOOD]

//>> SET_[CPLT_CTRL2_5_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_5_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_5_PGOOD]

//>> CLEAR_[CPLT_CTRL2_5_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_5_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_5_PGOOD]

//>> GET_[CPLT_CTRL2_5_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_5_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_5_PGOOD]

//>> GET_[CPLT_CTRL2_5_PGOOD]
static inline bool GET_CPLT_CTRL2_5_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_5_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_5_PGOOD]

//>> SET_[CPLT_CTRL2_6_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_6_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_6_PGOOD]

//>> SET_[CPLT_CTRL2_6_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_6_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_6_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_6_PGOOD]

//>> SET_[CPLT_CTRL2_6_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_6_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_6_PGOOD]

//>> CLEAR_[CPLT_CTRL2_6_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_6_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_6_PGOOD]

//>> GET_[CPLT_CTRL2_6_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_6_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_6_PGOOD]

//>> GET_[CPLT_CTRL2_6_PGOOD]
static inline bool GET_CPLT_CTRL2_6_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_6_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_6_PGOOD]

//>> SET_[CPLT_CTRL2_7_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_7_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_7_PGOOD]

//>> SET_[CPLT_CTRL2_7_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_7_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_7_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_7_PGOOD]

//>> SET_[CPLT_CTRL2_7_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_7_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_7_PGOOD]

//>> CLEAR_[CPLT_CTRL2_7_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_7_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_7_PGOOD]

//>> GET_[CPLT_CTRL2_7_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_7_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_7_PGOOD]

//>> GET_[CPLT_CTRL2_7_PGOOD]
static inline bool GET_CPLT_CTRL2_7_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_7_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_7_PGOOD]

//>> SET_[CPLT_CTRL2_8_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_8_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_8_PGOOD]

//>> SET_[CPLT_CTRL2_8_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_8_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_8_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_8_PGOOD]

//>> SET_[CPLT_CTRL2_8_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_8_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_8_PGOOD]

//>> CLEAR_[CPLT_CTRL2_8_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_8_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_8_PGOOD]

//>> GET_[CPLT_CTRL2_8_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_8_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_8_PGOOD]

//>> GET_[CPLT_CTRL2_8_PGOOD]
static inline bool GET_CPLT_CTRL2_8_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_8_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_8_PGOOD]

//>> SET_[CPLT_CTRL2_9_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_9_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_9_PGOOD]

//>> SET_[CPLT_CTRL2_9_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_9_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_9_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_9_PGOOD]

//>> SET_[CPLT_CTRL2_9_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_9_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_9_PGOOD]

//>> CLEAR_[CPLT_CTRL2_9_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_9_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_9_PGOOD]

//>> GET_[CPLT_CTRL2_9_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_9_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_9_PGOOD]

//>> GET_[CPLT_CTRL2_9_PGOOD]
static inline bool GET_CPLT_CTRL2_9_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_9_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_9_PGOOD]

//>> SET_[CPLT_CTRL2_10_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_10_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_10_PGOOD]

//>> SET_[CPLT_CTRL2_10_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_10_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_10_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_10_PGOOD]

//>> SET_[CPLT_CTRL2_10_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_10_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_10_PGOOD]

//>> CLEAR_[CPLT_CTRL2_10_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_10_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_10_PGOOD]

//>> GET_[CPLT_CTRL2_10_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_10_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_10_PGOOD]

//>> GET_[CPLT_CTRL2_10_PGOOD]
static inline bool GET_CPLT_CTRL2_10_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_10_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_10_PGOOD]

//>> SET_[CPLT_CTRL2_11_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_11_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_11_PGOOD]

//>> SET_[CPLT_CTRL2_11_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_11_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_11_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_11_PGOOD]

//>> SET_[CPLT_CTRL2_11_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_11_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_11_PGOOD]

//>> CLEAR_[CPLT_CTRL2_11_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_11_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_11_PGOOD]

//>> GET_[CPLT_CTRL2_11_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_11_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_11_PGOOD]

//>> GET_[CPLT_CTRL2_11_PGOOD]
static inline bool GET_CPLT_CTRL2_11_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_11_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_11_PGOOD]

//>> SET_[CPLT_CTRL2_12_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_12_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_12_PGOOD]

//>> SET_[CPLT_CTRL2_12_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_12_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_12_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_12_PGOOD]

//>> SET_[CPLT_CTRL2_12_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_12_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_12_PGOOD]

//>> CLEAR_[CPLT_CTRL2_12_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_12_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_12_PGOOD]

//>> GET_[CPLT_CTRL2_12_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_12_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_12_PGOOD]

//>> GET_[CPLT_CTRL2_12_PGOOD]
static inline bool GET_CPLT_CTRL2_12_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_12_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_12_PGOOD]

//>> SET_[CPLT_CTRL2_13_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_13_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_13_PGOOD]

//>> SET_[CPLT_CTRL2_13_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_13_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_13_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_13_PGOOD]

//>> SET_[CPLT_CTRL2_13_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_13_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_13_PGOOD]

//>> CLEAR_[CPLT_CTRL2_13_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_13_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_13_PGOOD]

//>> GET_[CPLT_CTRL2_13_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_13_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_13_PGOOD]

//>> GET_[CPLT_CTRL2_13_PGOOD]
static inline bool GET_CPLT_CTRL2_13_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_13_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_13_PGOOD]

//>> SET_[CPLT_CTRL2_14_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_14_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_14_PGOOD]

//>> SET_[CPLT_CTRL2_14_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_14_PGOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL2_14_PGOOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_14_PGOOD]

//>> SET_[CPLT_CTRL2_14_PGOOD]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL2_14_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL2_14_PGOOD]

//>> CLEAR_[CPLT_CTRL2_14_PGOOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL2_14_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL2_14_PGOOD]

//>> GET_[CPLT_CTRL2_14_PGOOD]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL2_14_PGOOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_14_PGOOD]

//>> GET_[CPLT_CTRL2_14_PGOOD]
static inline bool GET_CPLT_CTRL2_14_PGOOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL2_RW, CPLT_CTRL2_WO_CLEAR, CPLT_CTRL2_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL2_14_PGOOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL2_14_PGOOD]

//>> PREP_[CPLT_MASK0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_MASK0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_MASK0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_MASK0]

//>> GET_[CPLT_MASK0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_MASK0(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_MASK0;
#endif
    return fapi2::getScom(i_target, CPLT_MASK0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_MASK0]

//>> PUT_[CPLT_MASK0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_MASK0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_MASK0));
#endif
    return fapi2::putScom(i_target, CPLT_MASK0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_MASK0]


//>> SET_[CPLT_MASK0_ITR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPLT_MASK0_ITR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_MASK0));
#endif
    return o_data.insertFromRight<CPLT_MASK0_ITR_MASK,
           CPLT_MASK0_ITR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_MASK0_ITR_MASK]

//>> SET_[CPLT_MASK0_ITR_MASK]
static inline fapi2::buffer<uint64_t>& SET_CPLT_MASK0_ITR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_MASK0));
#endif
    return o_data.insertFromRight<CPLT_MASK0_ITR_MASK,
           CPLT_MASK0_ITR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_MASK0_ITR_MASK]

//>> GET_[CPLT_MASK0_ITR_MASK]
static inline fapi2::buffer<uint64_t>& GET_CPLT_MASK0_ITR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_MASK0));
#endif
    return i_data.extractToRight<CPLT_MASK0_ITR_MASK,
           CPLT_MASK0_ITR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_MASK0_ITR_MASK]

//>> PREP_[EPS_DBG_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_DBG_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = EPS_DBG_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_DBG_MODE_REG]

//>> GET_[EPS_DBG_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_DBG_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = EPS_DBG_MODE_REG;
#endif
    return fapi2::getScom(i_target, EPS_DBG_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_DBG_MODE_REG]

//>> PUT_[EPS_DBG_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_DBG_MODE_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return fapi2::putScom(i_target, EPS_DBG_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_DBG_MODE_REG]


//>> SET_[P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE]

//>> GET_[P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE]

//>> GET_[P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE]

//>> GET_[P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> CLEAR_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline bool GET_P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> CLEAR_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline bool GET_P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> CLEAR_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline bool GET_P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> CLEAR_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline bool GET_P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> SET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> CLEAR_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> GET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> GET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline bool GET_P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> CLEAR_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> GET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> GET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline bool GET_P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> CLEAR_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> GET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> GET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline bool GET_P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS]

//>> SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS]

//>> GET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS]

//>> SET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> SET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> SET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> CLEAR_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> GET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> GET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline bool GET_P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> SET_[P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]

//>> SET_[P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]

//>> GET_[P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]

//>> SET_[P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]

//>> SET_[P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]

//>> GET_[P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]

//>> SET_[P10_20_EPS_DBG_MODE_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_UNUSED,
           P10_20_EPS_DBG_MODE_REG_UNUSED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_UNUSED]

//>> SET_[P10_20_EPS_DBG_MODE_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EPS_DBG_MODE_REG_UNUSED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<P10_20_EPS_DBG_MODE_REG_UNUSED,
           P10_20_EPS_DBG_MODE_REG_UNUSED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EPS_DBG_MODE_REG_UNUSED]

//>> GET_[P10_20_EPS_DBG_MODE_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EPS_DBG_MODE_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<P10_20_EPS_DBG_MODE_REG_UNUSED,
           P10_20_EPS_DBG_MODE_REG_UNUSED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EPS_DBG_MODE_REG_UNUSED]

//>> PREP_[FSXCOMP_FSXLOG_CBS_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_CBS_CS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_CS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_CBS_CS]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_CBS_CS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_CS;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_CBS_CS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS]

//>> PUT_[FSXCOMP_FSXLOG_CBS_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_CBS_CS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_CBS_CS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_CBS_CS]

//>> PREP_[FSXCOMP_FSXLOG_CBS_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_CBS_CS_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_CS_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_CBS_CS_FSI]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_CBS_CS_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_CS_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_CBS_CS_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_FSI]

//>> PUT_[FSXCOMP_FSXLOG_CBS_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_CBS_CS_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_CBS_CS_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_CBS_CS_FSI]

//>> PREP_[FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE]


//>> SET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]
static inline bool GET_FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]
static inline bool GET_FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]
static inline bool GET_FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]
static inline bool GET_FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]
static inline bool GET_FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY,
           FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY,
           FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY,
           FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
           FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]

//>> SET_[FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
           FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]

//>> GET_[FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_CS, FSXCOMP_FSXLOG_CBS_CS_FSI, FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR,
           FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR]

//>> PREP_[FSXCOMP_FSXLOG_CBS_STAT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_CBS_STAT_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_STAT_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_CBS_STAT_FSI]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_CBS_STAT_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_STAT_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_CBS_STAT_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_FSI]

//>> PUT_[FSXCOMP_FSXLOG_CBS_STAT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_CBS_STAT_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_CBS_STAT_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_CBS_STAT_FSI]

//>> PREP_[FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_CBS_STAT_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_CBS_STAT_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_STAT_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_CBS_STAT_RO]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_CBS_STAT_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_CBS_STAT_RO;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_CBS_STAT_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_RO]

//>> PUT_[FSXCOMP_FSXLOG_CBS_STAT_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_CBS_STAT_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_CBS_STAT_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_CBS_STAT_RO]


//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_RESET_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD,
           FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD,
           FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD,
           FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE,
           FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE,
           FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE,
           FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE,
           FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE,
           FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE,
           FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE,
           FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE,
           FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE,
           FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> SET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> GET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline bool GET_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_CBS_STAT_FSI, FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW]


//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG,
           FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG,
           FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG,
           FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG]

//>> PREP_[PCB_OPCG_STOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PCB_OPCG_STOP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PCB_OPCG_STOP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PCB_OPCG_STOP]

//>> GET_[PCB_OPCG_STOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PCB_OPCG_STOP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PCB_OPCG_STOP;
#endif
    return fapi2::getScom(i_target, PCB_OPCG_STOP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PCB_OPCG_STOP]

//>> PUT_[PCB_OPCG_STOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PCB_OPCG_STOP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return fapi2::putScom(i_target, PCB_OPCG_STOP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PCB_OPCG_STOP]


//>> SET_[PCB_OPCG_STOP_PCB_OPCGSTOP]
static inline fapi2::buffer<uint64_t>& SET_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return o_data.insertFromRight<PCB_OPCG_STOP_PCB_OPCGSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PCB_OPCG_STOP_PCB_OPCGSTOP]

//>> SET_[PCB_OPCG_STOP_PCB_OPCGSTOP]
static inline fapi2::buffer<uint64_t>& SET_PCB_OPCG_STOP_PCB_OPCGSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return o_data.insertFromRight<PCB_OPCG_STOP_PCB_OPCGSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PCB_OPCG_STOP_PCB_OPCGSTOP]

//>> SET_[PCB_OPCG_STOP_PCB_OPCGSTOP]
static inline fapi2::buffer<uint64_t>& SET_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return o_data.setBit<PCB_OPCG_STOP_PCB_OPCGSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PCB_OPCG_STOP_PCB_OPCGSTOP]

//>> CLEAR_[PCB_OPCG_STOP_PCB_OPCGSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return o_data.clearBit<PCB_OPCG_STOP_PCB_OPCGSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PCB_OPCG_STOP_PCB_OPCGSTOP]

//>> GET_[PCB_OPCG_STOP_PCB_OPCGSTOP]
static inline fapi2::buffer<uint64_t>& GET_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return i_data.extractToRight<PCB_OPCG_STOP_PCB_OPCGSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PCB_OPCG_STOP_PCB_OPCGSTOP]

//>> GET_[PCB_OPCG_STOP_PCB_OPCGSTOP]
static inline bool GET_PCB_OPCG_STOP_PCB_OPCGSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PCB_OPCG_STOP));
#endif
    return i_data.getBit<PCB_OPCG_STOP_PCB_OPCGSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PCB_OPCG_STOP_PCB_OPCGSTOP]

//>> PREP_[REC_ERR_MST14_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_MST14_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST14_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REC_ERR_MST14_REG1]

//>> GET_[REC_ERR_MST14_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_MST14_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST14_REG1;
#endif
    return fapi2::getScom(i_target, REC_ERR_MST14_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REC_ERR_MST14_REG1]

//>> PUT_[REC_ERR_MST14_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_MST14_REG1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return fapi2::putScom(i_target, REC_ERR_MST14_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REC_ERR_MST14_REG1]


//>> SET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_16_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_16_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_16_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_16_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_16_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_16_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_16_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_16_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_16_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_16_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_16_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_16_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_16_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_16_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_16_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_16_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_16_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_16_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_17_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_17_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_17_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_17_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_17_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_17_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_17_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_17_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_17_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_17_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_17_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_17_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_17_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_17_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_17_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_17_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_17_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_17_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_18_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_18_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_18_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_18_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_18_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_18_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_18_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_18_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_18_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_18_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_18_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_18_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_18_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_18_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_18_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_18_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_18_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_18_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_19_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_19_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_19_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_19_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_19_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_19_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_19_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_19_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_19_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_19_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_19_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_19_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_19_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_19_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_19_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_19_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_19_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_19_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_20_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_20_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_20_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_20_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_20_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_20_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_20_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_20_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_20_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_20_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_20_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_20_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_20_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_20_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_20_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_20_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_20_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_20_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_21_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_21_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_21_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_21_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_21_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_21_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_21_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_21_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_21_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_21_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_21_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_21_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_21_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_21_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_21_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_21_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_21_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_21_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_22_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_22_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_22_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_22_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_22_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_22_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_22_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_22_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_22_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_22_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_22_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_22_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_22_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_22_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_22_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_22_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_22_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_22_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_23_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_23_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_23_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_23_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_23_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_23_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_23_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_23_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_23_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_23_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_23_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_23_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_23_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_23_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_23_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_23_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_23_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_23_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_24_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_24_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_24_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_24_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_24_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_24_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_24_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_24_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_24_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_24_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_24_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_24_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_24_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_24_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_24_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_24_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_24_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_24_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_25_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_25_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_25_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_25_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_25_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_25_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_25_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_25_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_25_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_25_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_25_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_25_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_25_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_25_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_25_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_25_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_25_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_25_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_26_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_26_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_26_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_26_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_26_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_26_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_26_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_26_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_26_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_26_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_26_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_26_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_26_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_26_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_26_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_26_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_26_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_26_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_27_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_27_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_27_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_27_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_27_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_27_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_27_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_27_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_27_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_27_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_27_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_27_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_27_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_27_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_27_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_27_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_27_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_27_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_28_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_28_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_28_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_28_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_28_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_28_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_28_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_28_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_28_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_28_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_28_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_28_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_28_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_28_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_28_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_28_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_28_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_28_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_29_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_29_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_29_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_29_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_29_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_29_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_29_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_29_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_29_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_29_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_29_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_29_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_29_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_29_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_29_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_29_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_29_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_29_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_30_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_30_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_30_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_30_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_30_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_30_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_30_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_30_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_30_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_30_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_30_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_30_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_30_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_30_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_30_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_30_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_30_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_30_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.setBit<REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.getBit<REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG1_31_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_31_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_31_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_31_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG1_31_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_31_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG1_31_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG1_31_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG1_31_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_31_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG1_31_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG1_31_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG1_31_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG1_31_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG1));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG1_31_MST14_ERROR_CODE,
           REC_ERR_MST14_REG1_31_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG1_31_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG1_31_MST14_ERROR_CODE]

//>> PREP_[SCAN64CONTSCAN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN64CONTSCAN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN64CONTSCAN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN64CONTSCAN]

//>> GET_[SCAN64CONTSCAN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN64CONTSCAN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN64CONTSCAN;
#endif
    return fapi2::getScom(i_target, SCAN64CONTSCAN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN64CONTSCAN]

//>> PUT_[SCAN64CONTSCAN]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN64CONTSCAN(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN64CONTSCAN));
#endif
    return fapi2::putScom(i_target, SCAN64CONTSCAN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN64CONTSCAN]


//>> SET_[SCAN64CONTSCAN_SCAN64CONTSCAN_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN64CONTSCAN_SCAN64CONTSCAN_REG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64CONTSCAN));
#endif
    return o_data.insertFromRight<SCAN64CONTSCAN_SCAN64CONTSCAN_REG,
           SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN64CONTSCAN_SCAN64CONTSCAN_REG]

//>> SET_[SCAN64CONTSCAN_SCAN64CONTSCAN_REG]
static inline fapi2::buffer<uint64_t>& SET_SCAN64CONTSCAN_SCAN64CONTSCAN_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64CONTSCAN));
#endif
    return o_data.insertFromRight<SCAN64CONTSCAN_SCAN64CONTSCAN_REG,
           SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN64CONTSCAN_SCAN64CONTSCAN_REG]

//>> GET_[SCAN64CONTSCAN_SCAN64CONTSCAN_REG]
static inline fapi2::buffer<uint64_t>& GET_SCAN64CONTSCAN_SCAN64CONTSCAN_REG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN64CONTSCAN));
#endif
    return i_data.extractToRight<SCAN64CONTSCAN_SCAN64CONTSCAN_REG,
           SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN64CONTSCAN_SCAN64CONTSCAN_REG]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
