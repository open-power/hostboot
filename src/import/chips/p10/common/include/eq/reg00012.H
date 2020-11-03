/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/eq/reg00012.H $           */
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

#ifndef __EQ_REG00012_H_
#define __EQ_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return fapi2::putScom(i_target, EPS_DBG_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_DBG_MODE_REG]


//>> SET_[EPS_DBG_MODE_REG_GLB_BRCST_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_GLB_BRCST_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_GLB_BRCST_MODE]

//>> SET_[EPS_DBG_MODE_REG_GLB_BRCST_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_GLB_BRCST_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_GLB_BRCST_MODE]

//>> GET_[EPS_DBG_MODE_REG_GLB_BRCST_MODE]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_GLB_BRCST_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_GLB_BRCST_MODE,
           EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_GLB_BRCST_MODE]

//>> SET_[EPS_DBG_MODE_REG_TRACE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_TRACE_SEL_MODE]

//>> SET_[EPS_DBG_MODE_REG_TRACE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_TRACE_SEL_MODE]

//>> GET_[EPS_DBG_MODE_REG_TRACE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_TRACE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_TRACE_SEL_MODE,
           EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_TRACE_SEL_MODE]

//>> SET_[EPS_DBG_MODE_REG_TRIG_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRIG_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_TRIG_SEL_MODE]

//>> SET_[EPS_DBG_MODE_REG_TRIG_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRIG_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_TRIG_SEL_MODE]

//>> GET_[EPS_DBG_MODE_REG_TRIG_SEL_MODE]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_TRIG_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_TRIG_SEL_MODE,
           EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_TRIG_SEL_MODE]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> CLEAR_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> GET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> GET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]
static inline bool GET_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> CLEAR_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> GET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> GET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]
static inline bool GET_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> CLEAR_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> GET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> GET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]
static inline bool GET_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> CLEAR_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> GET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> GET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]
static inline bool GET_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION]

//>> SET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> SET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> SET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> CLEAR_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> GET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_FREEZE_SEL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> GET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]
static inline bool GET_EPS_DBG_MODE_REG_FREEZE_SEL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_FREEZE_SEL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_FREEZE_SEL_MODE]

//>> SET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> SET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> SET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> CLEAR_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> GET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> GET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]
static inline bool GET_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE]

//>> SET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_RUN_ON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> SET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_RUN_ON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_RUN_ON,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> SET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_TRACE_RUN_ON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> CLEAR_[EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_TRACE_RUN_ON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> GET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_TRACE_RUN_ON,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> GET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]
static inline bool GET_EPS_DBG_MODE_REG_TRACE_RUN_ON(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_TRACE_RUN_ON>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_TRACE_RUN_ON]

//>> SET_[EPS_DBG_MODE_REG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_TRACE_RUN_STATUS]

//>> SET_[EPS_DBG_MODE_REG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_TRACE_RUN_STATUS]

//>> GET_[EPS_DBG_MODE_REG_TRACE_RUN_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_TRACE_RUN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_TRACE_RUN_STATUS,
           EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_TRACE_RUN_STATUS]

//>> SET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> SET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> SET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.setBit<EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> CLEAR_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.clearBit<EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> GET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_IS_FROZEN_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> GET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]
static inline bool GET_EPS_DBG_MODE_REG_IS_FROZEN_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.getBit<EPS_DBG_MODE_REG_IS_FROZEN_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_IS_FROZEN_STATUS]

//>> SET_[EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]

//>> SET_[EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]

//>> GET_[EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS]

//>> SET_[EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]

//>> SET_[EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]

//>> GET_[EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS,
           EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS]

//>> SET_[EPS_DBG_MODE_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_UNUSED,
           EPS_DBG_MODE_REG_UNUSED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_UNUSED]

//>> SET_[EPS_DBG_MODE_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& SET_EPS_DBG_MODE_REG_UNUSED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return o_data.insertFromRight<EPS_DBG_MODE_REG_UNUSED,
           EPS_DBG_MODE_REG_UNUSED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_DBG_MODE_REG_UNUSED]

//>> GET_[EPS_DBG_MODE_REG_UNUSED]
static inline fapi2::buffer<uint64_t>& GET_EPS_DBG_MODE_REG_UNUSED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_DBG_MODE_REG));
#endif
    return i_data.extractToRight<EPS_DBG_MODE_REG_UNUSED,
           EPS_DBG_MODE_REG_UNUSED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_UNUSED]

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
    FAPI_ERR("0:scom_eq Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_eq Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_eq Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_eq Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PCB_OPCG_STOP_PCB_OPCGSTOP]

//>> PREP_[QME_BCEBAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_BCEBAR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_BCEBAR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_BCEBAR1]

//>> GET_[QME_BCEBAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_BCEBAR1(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_BCEBAR1;
#endif
    return fapi2::getScom(i_target, QME_BCEBAR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_BCEBAR1]

//>> PUT_[QME_BCEBAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_BCEBAR1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_BCEBAR1));
#endif
    return fapi2::putScom(i_target, QME_BCEBAR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_BCEBAR1]


//>> SET_[QME_BCEBAR1_BASE]
static inline fapi2::buffer<uint64_t>& SET_QME_BCEBAR1_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_BCEBAR1));
#endif
    return o_data.insertFromRight<QME_BCEBAR1_BASE,
           QME_BCEBAR1_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_BCEBAR1_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_BCEBAR1_BASE]

//>> SET_[QME_BCEBAR1_BASE]
static inline fapi2::buffer<uint64_t>& SET_QME_BCEBAR1_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_BCEBAR1));
#endif
    return o_data.insertFromRight<QME_BCEBAR1_BASE,
           QME_BCEBAR1_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_BCEBAR1_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_BCEBAR1_BASE]

//>> GET_[QME_BCEBAR1_BASE]
static inline fapi2::buffer<uint64_t>& GET_QME_BCEBAR1_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_BCEBAR1));
#endif
    return i_data.extractToRight<QME_BCEBAR1_BASE,
           QME_BCEBAR1_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_BCEBAR1_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_BCEBAR1_BASE]

//>> SET_[QME_BCEBAR1_SIZE]
static inline fapi2::buffer<uint64_t>& SET_QME_BCEBAR1_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_BCEBAR1));
#endif
    return o_data.insertFromRight<QME_BCEBAR1_SIZE,
           QME_BCEBAR1_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_BCEBAR1_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_BCEBAR1_SIZE]

//>> SET_[QME_BCEBAR1_SIZE]
static inline fapi2::buffer<uint64_t>& SET_QME_BCEBAR1_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_BCEBAR1));
#endif
    return o_data.insertFromRight<QME_BCEBAR1_SIZE,
           QME_BCEBAR1_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_BCEBAR1_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_BCEBAR1_SIZE]

//>> GET_[QME_BCEBAR1_SIZE]
static inline fapi2::buffer<uint64_t>& GET_QME_BCEBAR1_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_BCEBAR1));
#endif
    return i_data.extractToRight<QME_BCEBAR1_SIZE,
           QME_BCEBAR1_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_BCEBAR1_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_BCEBAR1_SIZE]

//>> PREP_[QME_FLAGS_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_FLAGS_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_FLAGS_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_FLAGS_RW]

//>> GET_[QME_FLAGS_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_FLAGS_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_FLAGS_RW;
#endif
    return fapi2::getScom(i_target, QME_FLAGS_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_FLAGS_RW]

//>> PUT_[QME_FLAGS_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_FLAGS_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_FLAGS_RW, QME_FLAGS_WO_CLEAR, QME_FLAGS_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_FLAGS_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_FLAGS_RW]

//>> PREP_[QME_FLAGS_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_FLAGS_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_FLAGS_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_FLAGS_WO_CLEAR]

//>> GET_[QME_FLAGS_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_FLAGS_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_FLAGS_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_FLAGS_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_FLAGS_WO_CLEAR]

//>> PUT_[QME_FLAGS_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_FLAGS_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_FLAGS_RW, QME_FLAGS_WO_CLEAR, QME_FLAGS_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_FLAGS_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_FLAGS_WO_CLEAR]

//>> PREP_[QME_FLAGS_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_FLAGS_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_FLAGS_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_FLAGS_WO_OR]

//>> GET_[QME_FLAGS_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_FLAGS_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_FLAGS_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_FLAGS_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_FLAGS_WO_OR]

//>> PUT_[QME_FLAGS_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_FLAGS_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_FLAGS_RW, QME_FLAGS_WO_CLEAR, QME_FLAGS_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_FLAGS_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_FLAGS_WO_OR]


//>> SET_[QME_FLAGS_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_FLAGS_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FLAGS_RW, QME_FLAGS_WO_CLEAR, QME_FLAGS_WO_OR));
#endif
    return o_data.insertFromRight<QME_FLAGS_DATA,
           QME_FLAGS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_FLAGS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FLAGS_DATA]

//>> SET_[QME_FLAGS_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_FLAGS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FLAGS_RW, QME_FLAGS_WO_CLEAR, QME_FLAGS_WO_OR));
#endif
    return o_data.insertFromRight<QME_FLAGS_DATA,
           QME_FLAGS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_FLAGS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FLAGS_DATA]

//>> GET_[QME_FLAGS_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_FLAGS_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FLAGS_RW, QME_FLAGS_WO_CLEAR, QME_FLAGS_WO_OR));
#endif
    return i_data.extractToRight<QME_FLAGS_DATA,
           QME_FLAGS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_FLAGS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_FLAGS_DATA]

//>> PREP_[QME_PPEDBG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PPEDBG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PPEDBG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PPEDBG_RW]

//>> GET_[QME_PPEDBG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PPEDBG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PPEDBG_RW;
#endif
    return fapi2::getScom(i_target, QME_PPEDBG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PPEDBG_RW]

//>> PUT_[QME_PPEDBG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PPEDBG_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_PPEDBG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PPEDBG_RW]

//>> PREP_[QME_PPEDBG_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PPEDBG_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PPEDBG_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PPEDBG_WO_CLEAR]

//>> GET_[QME_PPEDBG_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PPEDBG_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PPEDBG_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_PPEDBG_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PPEDBG_WO_CLEAR]

//>> PUT_[QME_PPEDBG_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PPEDBG_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_PPEDBG_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PPEDBG_WO_CLEAR]

//>> PREP_[QME_PPEDBG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PPEDBG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PPEDBG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PPEDBG_WO_OR]

//>> GET_[QME_PPEDBG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PPEDBG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PPEDBG_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_PPEDBG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PPEDBG_WO_OR]

//>> PUT_[QME_PPEDBG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PPEDBG_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_PPEDBG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PPEDBG_WO_OR]


//>> SET_[QME_PPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_DBG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_DBG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_DBG]

//>> SET_[QME_PPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_DBG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_DBG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_DBG]

//>> SET_[QME_PPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_DBG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_EN_DBG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_DBG]

//>> CLEAR_[QME_PPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_EN_DBG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_EN_DBG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_EN_DBG]

//>> GET_[QME_PPEDBG_EN_DBG]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_EN_DBG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_EN_DBG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_DBG]

//>> GET_[QME_PPEDBG_EN_DBG]
static inline bool GET_QME_PPEDBG_EN_DBG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_EN_DBG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_EN_DBG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_DBG]

//>> SET_[QME_PPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_HALT_ON_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_HALT_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_HALT_ON_XSTOP]

//>> SET_[QME_PPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_HALT_ON_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_HALT_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_HALT_ON_XSTOP]

//>> SET_[QME_PPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_HALT_ON_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_HALT_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_HALT_ON_XSTOP]

//>> CLEAR_[QME_PPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_HALT_ON_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_HALT_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_HALT_ON_XSTOP]

//>> GET_[QME_PPEDBG_HALT_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_HALT_ON_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_HALT_ON_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_HALT_ON_XSTOP]

//>> GET_[QME_PPEDBG_HALT_ON_XSTOP]
static inline bool GET_QME_PPEDBG_HALT_ON_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_HALT_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_HALT_ON_XSTOP]

//>> SET_[QME_PPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_HALT_ON_TRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_HALT_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_HALT_ON_TRIG]

//>> SET_[QME_PPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_HALT_ON_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_HALT_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_HALT_ON_TRIG]

//>> SET_[QME_PPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_HALT_ON_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_HALT_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_HALT_ON_TRIG]

//>> CLEAR_[QME_PPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_HALT_ON_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_HALT_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_HALT_ON_TRIG]

//>> GET_[QME_PPEDBG_HALT_ON_TRIG]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_HALT_ON_TRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_HALT_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_HALT_ON_TRIG]

//>> GET_[QME_PPEDBG_HALT_ON_TRIG]
static inline bool GET_QME_PPEDBG_HALT_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_HALT_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_HALT_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_HALT_ON_TRIG]

//>> SET_[QME_PPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_COVERAGE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_COVERAGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_COVERAGE_MODE]

//>> SET_[QME_PPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_COVERAGE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_COVERAGE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_COVERAGE_MODE]

//>> SET_[QME_PPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_COVERAGE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_EN_COVERAGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_COVERAGE_MODE]

//>> CLEAR_[QME_PPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_EN_COVERAGE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_EN_COVERAGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_EN_COVERAGE_MODE]

//>> GET_[QME_PPEDBG_EN_COVERAGE_MODE]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_EN_COVERAGE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_EN_COVERAGE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_COVERAGE_MODE]

//>> GET_[QME_PPEDBG_EN_COVERAGE_MODE]
static inline bool GET_QME_PPEDBG_EN_COVERAGE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_EN_COVERAGE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_EN_COVERAGE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_COVERAGE_MODE]

//>> SET_[QME_PPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_INTR_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_INTR_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_INTR_ADDR]

//>> SET_[QME_PPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_INTR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_INTR_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_INTR_ADDR]

//>> SET_[QME_PPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_INTR_ADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_EN_INTR_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_INTR_ADDR]

//>> CLEAR_[QME_PPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_EN_INTR_ADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_EN_INTR_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_EN_INTR_ADDR]

//>> GET_[QME_PPEDBG_EN_INTR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_EN_INTR_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_EN_INTR_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_INTR_ADDR]

//>> GET_[QME_PPEDBG_EN_INTR_ADDR]
static inline bool GET_QME_PPEDBG_EN_INTR_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_EN_INTR_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_EN_INTR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_INTR_ADDR]

//>> SET_[QME_PPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_TRACE_EXTRA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_TRACE_EXTRA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_TRACE_EXTRA]

//>> SET_[QME_PPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_TRACE_EXTRA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_TRACE_EXTRA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_TRACE_EXTRA]

//>> SET_[QME_PPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_TRACE_EXTRA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_EN_TRACE_EXTRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_TRACE_EXTRA]

//>> CLEAR_[QME_PPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_EN_TRACE_EXTRA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_EN_TRACE_EXTRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_EN_TRACE_EXTRA]

//>> GET_[QME_PPEDBG_EN_TRACE_EXTRA]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_EN_TRACE_EXTRA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_EN_TRACE_EXTRA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_TRACE_EXTRA]

//>> GET_[QME_PPEDBG_EN_TRACE_EXTRA]
static inline bool GET_QME_PPEDBG_EN_TRACE_EXTRA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_EN_TRACE_EXTRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_EXTRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_TRACE_EXTRA]

//>> SET_[QME_PPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_TRACE_STALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_TRACE_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_TRACE_STALL]

//>> SET_[QME_PPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_TRACE_STALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_TRACE_STALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_TRACE_STALL]

//>> SET_[QME_PPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_TRACE_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_EN_TRACE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_TRACE_STALL]

//>> CLEAR_[QME_PPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_EN_TRACE_STALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_EN_TRACE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_EN_TRACE_STALL]

//>> GET_[QME_PPEDBG_EN_TRACE_STALL]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_EN_TRACE_STALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_EN_TRACE_STALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_TRACE_STALL]

//>> GET_[QME_PPEDBG_EN_TRACE_STALL]
static inline bool GET_QME_PPEDBG_EN_TRACE_STALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_EN_TRACE_STALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_EN_TRACE_STALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_TRACE_STALL]

//>> SET_[QME_PPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_WAIT_CYCLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_WAIT_CYCLES]

//>> SET_[QME_PPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_WAIT_CYCLES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_WAIT_CYCLES]

//>> SET_[QME_PPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_WAIT_CYCLES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_EN_WAIT_CYCLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_WAIT_CYCLES]

//>> CLEAR_[QME_PPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_EN_WAIT_CYCLES(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_EN_WAIT_CYCLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_EN_WAIT_CYCLES]

//>> GET_[QME_PPEDBG_EN_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_EN_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_EN_WAIT_CYCLES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_WAIT_CYCLES]

//>> GET_[QME_PPEDBG_EN_WAIT_CYCLES]
static inline bool GET_QME_PPEDBG_EN_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_EN_WAIT_CYCLES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_EN_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_WAIT_CYCLES]

//>> SET_[QME_PPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_FULL_SPEED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_FULL_SPEED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_FULL_SPEED]

//>> SET_[QME_PPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_FULL_SPEED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_FULL_SPEED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_FULL_SPEED]

//>> SET_[QME_PPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_FULL_SPEED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_EN_FULL_SPEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_FULL_SPEED]

//>> CLEAR_[QME_PPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_EN_FULL_SPEED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_EN_FULL_SPEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_EN_FULL_SPEED]

//>> GET_[QME_PPEDBG_EN_FULL_SPEED]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_EN_FULL_SPEED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_EN_FULL_SPEED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_FULL_SPEED]

//>> GET_[QME_PPEDBG_EN_FULL_SPEED]
static inline bool GET_QME_PPEDBG_EN_FULL_SPEED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_EN_FULL_SPEED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_EN_FULL_SPEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_FULL_SPEED]

//>> SET_[QME_PPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_DIS_FLOW_CHANGE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_DIS_FLOW_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_DIS_FLOW_CHANGE]

//>> SET_[QME_PPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_DIS_FLOW_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_DIS_FLOW_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_DIS_FLOW_CHANGE]

//>> SET_[QME_PPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_DIS_FLOW_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_DIS_FLOW_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_DIS_FLOW_CHANGE]

//>> CLEAR_[QME_PPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_DIS_FLOW_CHANGE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_DIS_FLOW_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_DIS_FLOW_CHANGE]

//>> GET_[QME_PPEDBG_DIS_FLOW_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_DIS_FLOW_CHANGE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_DIS_FLOW_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_DIS_FLOW_CHANGE]

//>> GET_[QME_PPEDBG_DIS_FLOW_CHANGE]
static inline bool GET_QME_PPEDBG_DIS_FLOW_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_DIS_FLOW_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_DIS_FLOW_CHANGE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_DIS_FLOW_CHANGE]

//>> SET_[QME_PPEDBG_TRACE_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_MODE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_MODE_SEL,
           QME_PPEDBG_TRACE_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_TRACE_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_MODE_SEL]

//>> SET_[QME_PPEDBG_TRACE_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_MODE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_MODE_SEL,
           QME_PPEDBG_TRACE_MODE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_TRACE_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_MODE_SEL]

//>> GET_[QME_PPEDBG_TRACE_MODE_SEL]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_TRACE_MODE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_TRACE_MODE_SEL,
           QME_PPEDBG_TRACE_MODE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_TRACE_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_TRACE_MODE_SEL]

//>> SET_[QME_PPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_MARK_TRACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_MARK_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_EN_MARK_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_MARK_TRACE]

//>> SET_[QME_PPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_MARK_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_MARK_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_EN_MARK_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_MARK_TRACE]

//>> SET_[QME_PPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_MARK_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_EN_MARK_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_EN_MARK_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_MARK_TRACE]

//>> CLEAR_[QME_PPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_EN_MARK_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_EN_MARK_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_EN_MARK_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_EN_MARK_TRACE]

//>> GET_[QME_PPEDBG_EN_MARK_TRACE]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_EN_MARK_TRACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_EN_MARK_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_EN_MARK_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_MARK_TRACE]

//>> GET_[QME_PPEDBG_EN_MARK_TRACE]
static inline bool GET_QME_PPEDBG_EN_MARK_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_EN_MARK_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_EN_MARK_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_MARK_TRACE]

//>> SET_[QME_PPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_EE_TRACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_EE_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_EE_TRACE]

//>> SET_[QME_PPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_EE_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_EN_EE_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_EE_TRACE]

//>> SET_[QME_PPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_EN_EE_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_EN_EE_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_EN_EE_TRACE]

//>> CLEAR_[QME_PPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_EN_EE_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_EN_EE_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_EN_EE_TRACE]

//>> GET_[QME_PPEDBG_EN_EE_TRACE]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_EN_EE_TRACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_EN_EE_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_EE_TRACE]

//>> GET_[QME_PPEDBG_EN_EE_TRACE]
static inline bool GET_QME_PPEDBG_EN_EE_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_EN_EE_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_EN_EE_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_EN_EE_TRACE]

//>> SET_[QME_PPEDBG_TRACE_LOWER_SEL1]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_LOWER_SEL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_LOWER_SEL1,
           QME_PPEDBG_TRACE_LOWER_SEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_TRACE_LOWER_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_LOWER_SEL1]

//>> SET_[QME_PPEDBG_TRACE_LOWER_SEL1]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_LOWER_SEL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_LOWER_SEL1,
           QME_PPEDBG_TRACE_LOWER_SEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_TRACE_LOWER_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_LOWER_SEL1]

//>> GET_[QME_PPEDBG_TRACE_LOWER_SEL1]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_TRACE_LOWER_SEL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_TRACE_LOWER_SEL1,
           QME_PPEDBG_TRACE_LOWER_SEL1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_TRACE_LOWER_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_TRACE_LOWER_SEL1]

//>> SET_[QME_PPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_FIR_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_FIR_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_FIR_TRIGGER]

//>> SET_[QME_PPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_FIR_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_FIR_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_FIR_TRIGGER]

//>> SET_[QME_PPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_FIR_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_FIR_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_FIR_TRIGGER]

//>> CLEAR_[QME_PPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_FIR_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_FIR_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_FIR_TRIGGER]

//>> GET_[QME_PPEDBG_FIR_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_FIR_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_FIR_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_FIR_TRIGGER]

//>> GET_[QME_PPEDBG_FIR_TRIGGER]
static inline bool GET_QME_PPEDBG_FIR_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_FIR_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_FIR_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_FIR_TRIGGER]

//>> SET_[QME_PPEDBG_MIB_GPIO]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_MIB_GPIO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_MIB_GPIO,
           QME_PPEDBG_MIB_GPIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_MIB_GPIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_MIB_GPIO]

//>> SET_[QME_PPEDBG_MIB_GPIO]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_MIB_GPIO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_MIB_GPIO,
           QME_PPEDBG_MIB_GPIO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_MIB_GPIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_MIB_GPIO]

//>> GET_[QME_PPEDBG_MIB_GPIO]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_MIB_GPIO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_MIB_GPIO,
           QME_PPEDBG_MIB_GPIO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_MIB_GPIO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_MIB_GPIO]

//>> SET_[QME_PPEDBG_TRACE_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_DATA_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_DATA_SEL,
           QME_PPEDBG_TRACE_DATA_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_TRACE_DATA_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_DATA_SEL]

//>> SET_[QME_PPEDBG_TRACE_DATA_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_DATA_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_DATA_SEL,
           QME_PPEDBG_TRACE_DATA_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_TRACE_DATA_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_DATA_SEL]

//>> GET_[QME_PPEDBG_TRACE_DATA_SEL]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_TRACE_DATA_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_TRACE_DATA_SEL,
           QME_PPEDBG_TRACE_DATA_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_TRACE_DATA_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_TRACE_DATA_SEL]

//>> SET_[QME_PPEDBG_QHTM_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_QHTM_TRACE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_QHTM_TRACE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_QHTM_TRACE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_QHTM_TRACE_SEL]

//>> SET_[QME_PPEDBG_QHTM_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_QHTM_TRACE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_QHTM_TRACE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_QHTM_TRACE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_QHTM_TRACE_SEL]

//>> SET_[QME_PPEDBG_QHTM_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_QHTM_TRACE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_QHTM_TRACE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_QHTM_TRACE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_QHTM_TRACE_SEL]

//>> CLEAR_[QME_PPEDBG_QHTM_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_QHTM_TRACE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_QHTM_TRACE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_QHTM_TRACE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_QHTM_TRACE_SEL]

//>> GET_[QME_PPEDBG_QHTM_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_QHTM_TRACE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_QHTM_TRACE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_QHTM_TRACE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_QHTM_TRACE_SEL]

//>> GET_[QME_PPEDBG_QHTM_TRACE_SEL]
static inline bool GET_QME_PPEDBG_QHTM_TRACE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_QHTM_TRACE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_QHTM_TRACE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_QHTM_TRACE_SEL]

//>> SET_[QME_PPEDBG_TRACE_EXT_SEL0]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_EXT_SEL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_EXT_SEL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_TRACE_EXT_SEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_EXT_SEL0]

//>> SET_[QME_PPEDBG_TRACE_EXT_SEL0]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_EXT_SEL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_EXT_SEL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_TRACE_EXT_SEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_EXT_SEL0]

//>> SET_[QME_PPEDBG_TRACE_EXT_SEL0]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_EXT_SEL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_TRACE_EXT_SEL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_TRACE_EXT_SEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_EXT_SEL0]

//>> CLEAR_[QME_PPEDBG_TRACE_EXT_SEL0]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_TRACE_EXT_SEL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_TRACE_EXT_SEL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_TRACE_EXT_SEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_TRACE_EXT_SEL0]

//>> GET_[QME_PPEDBG_TRACE_EXT_SEL0]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_TRACE_EXT_SEL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_TRACE_EXT_SEL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_TRACE_EXT_SEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_TRACE_EXT_SEL0]

//>> GET_[QME_PPEDBG_TRACE_EXT_SEL0]
static inline bool GET_QME_PPEDBG_TRACE_EXT_SEL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_TRACE_EXT_SEL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_TRACE_EXT_SEL0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_TRACE_EXT_SEL0]

//>> SET_[QME_PPEDBG_TRACE_MODE_SEL1]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_MODE_SEL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_MODE_SEL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_TRACE_MODE_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_MODE_SEL1]

//>> SET_[QME_PPEDBG_TRACE_MODE_SEL1]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_MODE_SEL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_MODE_SEL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_TRACE_MODE_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_MODE_SEL1]

//>> SET_[QME_PPEDBG_TRACE_MODE_SEL1]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_MODE_SEL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.setBit<QME_PPEDBG_TRACE_MODE_SEL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_PPEDBG_TRACE_MODE_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_MODE_SEL1]

//>> CLEAR_[QME_PPEDBG_TRACE_MODE_SEL1]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PPEDBG_TRACE_MODE_SEL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.clearBit<QME_PPEDBG_TRACE_MODE_SEL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_PPEDBG_TRACE_MODE_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PPEDBG_TRACE_MODE_SEL1]

//>> GET_[QME_PPEDBG_TRACE_MODE_SEL1]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_TRACE_MODE_SEL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_TRACE_MODE_SEL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_TRACE_MODE_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_TRACE_MODE_SEL1]

//>> GET_[QME_PPEDBG_TRACE_MODE_SEL1]
static inline bool GET_QME_PPEDBG_TRACE_MODE_SEL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.getBit<QME_PPEDBG_TRACE_MODE_SEL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_PPEDBG_TRACE_MODE_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_TRACE_MODE_SEL1]

//>> SET_[QME_PPEDBG_TRACE_DATA_SEL1]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_DATA_SEL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_DATA_SEL1,
           QME_PPEDBG_TRACE_DATA_SEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEDBG_TRACE_DATA_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_DATA_SEL1]

//>> SET_[QME_PPEDBG_TRACE_DATA_SEL1]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEDBG_TRACE_DATA_SEL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return o_data.insertFromRight<QME_PPEDBG_TRACE_DATA_SEL1,
           QME_PPEDBG_TRACE_DATA_SEL1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEDBG_TRACE_DATA_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEDBG_TRACE_DATA_SEL1]

//>> GET_[QME_PPEDBG_TRACE_DATA_SEL1]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEDBG_TRACE_DATA_SEL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEDBG_RW, QME_PPEDBG_WO_CLEAR, QME_PPEDBG_WO_OR));
#endif
    return i_data.extractToRight<QME_PPEDBG_TRACE_DATA_SEL1,
           QME_PPEDBG_TRACE_DATA_SEL1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEDBG_TRACE_DATA_SEL1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEDBG_TRACE_DATA_SEL1]

//>> PREP_[QME_PTSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PTSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PTSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PTSR]

//>> GET_[QME_PTSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PTSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PTSR;
#endif
    return fapi2::getScom(i_target, QME_PTSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PTSR]

//>> PUT_[QME_PTSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PTSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return fapi2::putScom(i_target, QME_PTSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PTSR]


//>> SET_[QME_PTSR_0_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_0_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_0_DATA,
           QME_PTSR_0_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PTSR_0_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_0_DATA]

//>> SET_[QME_PTSR_0_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_0_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_0_DATA,
           QME_PTSR_0_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PTSR_0_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_0_DATA]

//>> GET_[QME_PTSR_0_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PTSR_0_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return i_data.extractToRight<QME_PTSR_0_DATA,
           QME_PTSR_0_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PTSR_0_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PTSR_0_DATA]

//>> SET_[QME_PTSR_1_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_1_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_1_DATA,
           QME_PTSR_1_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PTSR_1_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_1_DATA]

//>> SET_[QME_PTSR_1_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_1_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_1_DATA,
           QME_PTSR_1_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PTSR_1_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_1_DATA]

//>> GET_[QME_PTSR_1_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PTSR_1_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return i_data.extractToRight<QME_PTSR_1_DATA,
           QME_PTSR_1_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PTSR_1_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PTSR_1_DATA]

//>> SET_[QME_PTSR_2_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_2_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_2_DATA,
           QME_PTSR_2_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PTSR_2_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_2_DATA]

//>> SET_[QME_PTSR_2_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_2_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_2_DATA,
           QME_PTSR_2_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PTSR_2_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_2_DATA]

//>> GET_[QME_PTSR_2_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PTSR_2_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return i_data.extractToRight<QME_PTSR_2_DATA,
           QME_PTSR_2_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PTSR_2_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PTSR_2_DATA]

//>> SET_[QME_PTSR_3_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_3_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_3_DATA,
           QME_PTSR_3_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PTSR_3_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_3_DATA]

//>> SET_[QME_PTSR_3_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_3_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_3_DATA,
           QME_PTSR_3_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PTSR_3_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_3_DATA]

//>> GET_[QME_PTSR_3_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PTSR_3_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return i_data.extractToRight<QME_PTSR_3_DATA,
           QME_PTSR_3_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PTSR_3_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PTSR_3_DATA]

//>> SET_[QME_PTSR_4_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_4_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_4_DATA,
           QME_PTSR_4_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PTSR_4_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_4_DATA]

//>> SET_[QME_PTSR_4_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_4_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_4_DATA,
           QME_PTSR_4_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PTSR_4_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_4_DATA]

//>> GET_[QME_PTSR_4_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PTSR_4_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return i_data.extractToRight<QME_PTSR_4_DATA,
           QME_PTSR_4_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PTSR_4_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PTSR_4_DATA]

//>> SET_[QME_PTSR_5_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_5_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_5_DATA,
           QME_PTSR_5_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PTSR_5_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_5_DATA]

//>> SET_[QME_PTSR_5_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_5_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_5_DATA,
           QME_PTSR_5_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PTSR_5_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_5_DATA]

//>> GET_[QME_PTSR_5_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PTSR_5_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return i_data.extractToRight<QME_PTSR_5_DATA,
           QME_PTSR_5_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PTSR_5_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PTSR_5_DATA]

//>> SET_[QME_PTSR_6_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_6_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_6_DATA,
           QME_PTSR_6_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PTSR_6_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_6_DATA]

//>> SET_[QME_PTSR_6_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_6_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_6_DATA,
           QME_PTSR_6_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PTSR_6_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_6_DATA]

//>> GET_[QME_PTSR_6_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PTSR_6_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return i_data.extractToRight<QME_PTSR_6_DATA,
           QME_PTSR_6_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PTSR_6_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PTSR_6_DATA]

//>> SET_[QME_PTSR_7_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_7_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_7_DATA,
           QME_PTSR_7_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PTSR_7_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_7_DATA]

//>> SET_[QME_PTSR_7_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_PTSR_7_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return o_data.insertFromRight<QME_PTSR_7_DATA,
           QME_PTSR_7_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PTSR_7_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PTSR_7_DATA]

//>> GET_[QME_PTSR_7_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_PTSR_7_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PTSR));
#endif
    return i_data.extractToRight<QME_PTSR_7_DATA,
           QME_PTSR_7_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PTSR_7_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PTSR_7_DATA]

//>> PREP_[QME_RCIMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RCIMR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCIMR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RCIMR]

//>> GET_[QME_RCIMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RCIMR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCIMR;
#endif
    return fapi2::getScom(i_target, QME_RCIMR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RCIMR]

//>> PUT_[QME_RCIMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RCIMR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return fapi2::putScom(i_target, QME_RCIMR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RCIMR]


//>> SET_[QME_RCIMR_P0]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_P0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_P0,
           QME_RCIMR_P0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCIMR_P0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_P0]

//>> SET_[QME_RCIMR_P0]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_P0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_P0,
           QME_RCIMR_P0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCIMR_P0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_P0]

//>> GET_[QME_RCIMR_P0]
static inline fapi2::buffer<uint64_t>& GET_QME_RCIMR_P0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return i_data.extractToRight<QME_RCIMR_P0,
           QME_RCIMR_P0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCIMR_P0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCIMR_P0]

//>> SET_[QME_RCIMR_X0]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_X0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_X0,
           QME_RCIMR_X0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCIMR_X0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_X0]

//>> SET_[QME_RCIMR_X0]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_X0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_X0,
           QME_RCIMR_X0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCIMR_X0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_X0]

//>> GET_[QME_RCIMR_X0]
static inline fapi2::buffer<uint64_t>& GET_QME_RCIMR_X0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return i_data.extractToRight<QME_RCIMR_X0,
           QME_RCIMR_X0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCIMR_X0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCIMR_X0]

//>> SET_[QME_RCIMR_P1]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_P1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_P1,
           QME_RCIMR_P1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCIMR_P1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_P1]

//>> SET_[QME_RCIMR_P1]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_P1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_P1,
           QME_RCIMR_P1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCIMR_P1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_P1]

//>> GET_[QME_RCIMR_P1]
static inline fapi2::buffer<uint64_t>& GET_QME_RCIMR_P1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return i_data.extractToRight<QME_RCIMR_P1,
           QME_RCIMR_P1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCIMR_P1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCIMR_P1]

//>> SET_[QME_RCIMR_X1]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_X1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_X1,
           QME_RCIMR_X1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCIMR_X1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_X1]

//>> SET_[QME_RCIMR_X1]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_X1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_X1,
           QME_RCIMR_X1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCIMR_X1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_X1]

//>> GET_[QME_RCIMR_X1]
static inline fapi2::buffer<uint64_t>& GET_QME_RCIMR_X1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return i_data.extractToRight<QME_RCIMR_X1,
           QME_RCIMR_X1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCIMR_X1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCIMR_X1]

//>> SET_[QME_RCIMR_P2]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_P2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_P2,
           QME_RCIMR_P2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCIMR_P2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_P2]

//>> SET_[QME_RCIMR_P2]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_P2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_P2,
           QME_RCIMR_P2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCIMR_P2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_P2]

//>> GET_[QME_RCIMR_P2]
static inline fapi2::buffer<uint64_t>& GET_QME_RCIMR_P2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return i_data.extractToRight<QME_RCIMR_P2,
           QME_RCIMR_P2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCIMR_P2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCIMR_P2]

//>> SET_[QME_RCIMR_X2]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_X2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_X2,
           QME_RCIMR_X2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCIMR_X2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_X2]

//>> SET_[QME_RCIMR_X2]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_X2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_X2,
           QME_RCIMR_X2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCIMR_X2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_X2]

//>> GET_[QME_RCIMR_X2]
static inline fapi2::buffer<uint64_t>& GET_QME_RCIMR_X2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return i_data.extractToRight<QME_RCIMR_X2,
           QME_RCIMR_X2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCIMR_X2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCIMR_X2]

//>> SET_[QME_RCIMR_P3]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_P3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_P3,
           QME_RCIMR_P3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCIMR_P3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_P3]

//>> SET_[QME_RCIMR_P3]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_P3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_P3,
           QME_RCIMR_P3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCIMR_P3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_P3]

//>> GET_[QME_RCIMR_P3]
static inline fapi2::buffer<uint64_t>& GET_QME_RCIMR_P3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return i_data.extractToRight<QME_RCIMR_P3,
           QME_RCIMR_P3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCIMR_P3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCIMR_P3]

//>> SET_[QME_RCIMR_X3]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_X3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_X3,
           QME_RCIMR_X3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCIMR_X3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_X3]

//>> SET_[QME_RCIMR_X3]
static inline fapi2::buffer<uint64_t>& SET_QME_RCIMR_X3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return o_data.insertFromRight<QME_RCIMR_X3,
           QME_RCIMR_X3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCIMR_X3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCIMR_X3]

//>> GET_[QME_RCIMR_X3]
static inline fapi2::buffer<uint64_t>& GET_QME_RCIMR_X3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCIMR));
#endif
    return i_data.extractToRight<QME_RCIMR_X3,
           QME_RCIMR_X3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCIMR_X3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCIMR_X3]

//>> PREP_[QME_RCTAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RCTAR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCTAR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RCTAR1]

//>> GET_[QME_RCTAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RCTAR1(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCTAR1;
#endif
    return fapi2::getScom(i_target, QME_RCTAR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RCTAR1]

//>> PUT_[QME_RCTAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RCTAR1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RCTAR1));
#endif
    return fapi2::putScom(i_target, QME_RCTAR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RCTAR1]


//>> SET_[QME_RCTAR1_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_RCTAR1_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCTAR1));
#endif
    return o_data.insertFromRight<QME_RCTAR1_DATA,
           QME_RCTAR1_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCTAR1_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCTAR1_DATA]

//>> SET_[QME_RCTAR1_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_RCTAR1_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCTAR1));
#endif
    return o_data.insertFromRight<QME_RCTAR1_DATA,
           QME_RCTAR1_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCTAR1_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCTAR1_DATA]

//>> GET_[QME_RCTAR1_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_RCTAR1_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCTAR1));
#endif
    return i_data.extractToRight<QME_RCTAR1_DATA,
           QME_RCTAR1_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCTAR1_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCTAR1_DATA]

//>> PREP_[QME_SCOM_PBTXTR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_PBTXTR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_PBTXTR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_PBTXTR0]

//>> GET_[QME_SCOM_PBTXTR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_PBTXTR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_PBTXTR0;
#endif
    return fapi2::getScom(i_target, QME_SCOM_PBTXTR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0]

//>> PUT_[QME_SCOM_PBTXTR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_PBTXTR0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return fapi2::putScom(i_target, QME_SCOM_PBTXTR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_PBTXTR0]


//>> SET_[QME_SCOM_PBTXTR0_VALID]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_VALID,
           QME_SCOM_PBTXTR0_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_VALID]

//>> SET_[QME_SCOM_PBTXTR0_VALID]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_VALID,
           QME_SCOM_PBTXTR0_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_VALID]

//>> GET_[QME_SCOM_PBTXTR0_VALID]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR0_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR0_VALID,
           QME_SCOM_PBTXTR0_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR0_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0_VALID]

//>> SET_[QME_SCOM_PBTXTR0_0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_0,
           QME_SCOM_PBTXTR0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_0]

//>> SET_[QME_SCOM_PBTXTR0_0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_0,
           QME_SCOM_PBTXTR0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_0]

//>> GET_[QME_SCOM_PBTXTR0_0]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR0_0,
           QME_SCOM_PBTXTR0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0_0]

//>> SET_[QME_SCOM_PBTXTR0_1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_1,
           QME_SCOM_PBTXTR0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_1]

//>> SET_[QME_SCOM_PBTXTR0_1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_1,
           QME_SCOM_PBTXTR0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_1]

//>> GET_[QME_SCOM_PBTXTR0_1]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR0_1,
           QME_SCOM_PBTXTR0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0_1]

//>> SET_[QME_SCOM_PBTXTR0_2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_2,
           QME_SCOM_PBTXTR0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_2]

//>> SET_[QME_SCOM_PBTXTR0_2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_2,
           QME_SCOM_PBTXTR0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_2]

//>> GET_[QME_SCOM_PBTXTR0_2]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR0_2,
           QME_SCOM_PBTXTR0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0_2]

//>> SET_[QME_SCOM_PBTXTR0_3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_3,
           QME_SCOM_PBTXTR0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_3]

//>> SET_[QME_SCOM_PBTXTR0_3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_3,
           QME_SCOM_PBTXTR0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_3]

//>> GET_[QME_SCOM_PBTXTR0_3]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR0_3,
           QME_SCOM_PBTXTR0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0_3]

//>> SET_[QME_SCOM_PBTXTR0_4]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_4,
           QME_SCOM_PBTXTR0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_4]

//>> SET_[QME_SCOM_PBTXTR0_4]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_4,
           QME_SCOM_PBTXTR0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_4]

//>> GET_[QME_SCOM_PBTXTR0_4]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR0_4,
           QME_SCOM_PBTXTR0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0_4]

//>> SET_[QME_SCOM_PBTXTR0_5]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_5,
           QME_SCOM_PBTXTR0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_5]

//>> SET_[QME_SCOM_PBTXTR0_5]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_5,
           QME_SCOM_PBTXTR0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_5]

//>> GET_[QME_SCOM_PBTXTR0_5]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR0_5,
           QME_SCOM_PBTXTR0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0_5]

//>> SET_[QME_SCOM_PBTXTR0_6]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_6,
           QME_SCOM_PBTXTR0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_6]

//>> SET_[QME_SCOM_PBTXTR0_6]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_6,
           QME_SCOM_PBTXTR0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_6]

//>> GET_[QME_SCOM_PBTXTR0_6]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR0_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR0_6,
           QME_SCOM_PBTXTR0_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0_6]

//>> SET_[QME_SCOM_PBTXTR0_7]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_7,
           QME_SCOM_PBTXTR0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_7]

//>> SET_[QME_SCOM_PBTXTR0_7]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR0_7,
           QME_SCOM_PBTXTR0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR0_7]

//>> GET_[QME_SCOM_PBTXTR0_7]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR0));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR0_7,
           QME_SCOM_PBTXTR0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR0_7]

//>> PREP_[QME_SCOM_XIRAMDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XIRAMDBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIRAMDBG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XIRAMDBG]

//>> GET_[QME_SCOM_XIRAMDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XIRAMDBG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIRAMDBG;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XIRAMDBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG]

//>> PUT_[QME_SCOM_XIRAMDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XIRAMDBG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XIRAMDBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XIRAMDBG]


//>> SET_[QME_SCOM_XIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_HS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_HS]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_HS]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_HS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_HS]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_HS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_HS]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_HS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_HS]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_HS]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_HS]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_HC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_HC,
           QME_SCOM_XIRAMDBG_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_HC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_HC,
           QME_SCOM_XIRAMDBG_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_HC]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_HC]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_HC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_HC,
           QME_SCOM_XIRAMDBG_XSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_HC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_HCP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_HCP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_HCP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_HCP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_HCP]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_HCP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_HCP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_HCP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_HCP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_HCP]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_HCP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_RIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_RIP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_RIP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_RIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_RIP]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_RIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_RIP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_RIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_RIP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_RIP]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_RIP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_SIP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_SIP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_SIP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_SIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_SIP]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_SIP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_SIP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_SIP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_SIP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_SIP]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_SIP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_TRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_TRAP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_TRAP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_TRAP]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_TRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_TRAP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_TRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_TRAP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_TRAP]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_TRAP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_IAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_IAC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_IAC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_IAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_IAC]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_IAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_IAC]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_IAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_IAC]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_IAC]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_IAC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_SIB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_SIB,
           QME_SCOM_XIRAMDBG_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_SIB]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_SIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_SIB,
           QME_SCOM_XIRAMDBG_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_SIB]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_SIB]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_SIB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_SIB,
           QME_SCOM_XIRAMDBG_XSR_SIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SIB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_SIB]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_RDAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_RDAC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_RDAC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_RDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_RDAC]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_RDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_RDAC]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_RDAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_RDAC]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_RDAC]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_RDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_RDAC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_WDAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_WDAC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_WDAC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_WDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_WDAC]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_WDAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_WDAC]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_WDAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_WDAC]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_WDAC]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WDAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_WDAC]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_WS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_WS]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_WS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_WS]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_WS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_WS]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_WS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_WS]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_WS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_WS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_WS]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_WS]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_WS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_WS]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_TRH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_TRH]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_TRH]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_TRH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_TRH]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_TRH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_TRH]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_TRH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_TRH]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_TRH]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_TRH]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_SMS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_SMS,
           QME_SCOM_XIRAMDBG_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SMS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_SMS]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_SMS,
           QME_SCOM_XIRAMDBG_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SMS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_SMS]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_SMS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_SMS,
           QME_SCOM_XIRAMDBG_XSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_SMS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_SMS]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_LP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_LP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_LP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_LP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_LP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_LP]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_LP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_LP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_LP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_LP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_LP]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_LP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_EP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_EP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_EP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_EP]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_EP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_EP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_EP]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_EP]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_EP]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_PTR]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_PTR]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_PTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_PTR]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_PTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_PTR]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_PTR]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_PTR]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_PTR]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_ST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_ST]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_ST]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_ST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_ST]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_ST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_ST]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_ST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_ST]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_ST]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_ST]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_MFE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_MFE]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_MFE]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_MFE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.setBit<QME_SCOM_XIRAMDBG_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_MFE]

//>> CLEAR_[QME_SCOM_XIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XIRAMDBG_XSR_MFE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.clearBit<QME_SCOM_XIRAMDBG_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XIRAMDBG_XSR_MFE]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_MFE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_MFE]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_MFE]
static inline bool GET_QME_SCOM_XIRAMDBG_XSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.getBit<QME_SCOM_XIRAMDBG_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_MFE]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_MCS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_MCS,
           QME_SCOM_XIRAMDBG_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_MCS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_MCS]

//>> SET_[QME_SCOM_XIRAMDBG_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_XSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_XSR_MCS,
           QME_SCOM_XIRAMDBG_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_MCS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_XSR_MCS]

//>> GET_[QME_SCOM_XIRAMDBG_XSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_XSR_MCS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_XSR_MCS,
           QME_SCOM_XIRAMDBG_XSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_XSR_MCS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_XSR_MCS]

//>> SET_[QME_SCOM_XIRAMDBG_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_SPRG0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_SPRG0,
           QME_SCOM_XIRAMDBG_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_SPRG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_SPRG0]

//>> SET_[QME_SCOM_XIRAMDBG_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMDBG_SPRG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMDBG_SPRG0,
           QME_SCOM_XIRAMDBG_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_SPRG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMDBG_SPRG0]

//>> GET_[QME_SCOM_XIRAMDBG_SPRG0]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMDBG_SPRG0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMDBG));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMDBG_SPRG0,
           QME_SCOM_XIRAMDBG_SPRG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMDBG_SPRG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMDBG_SPRG0]

//>> PREP_[QME_SCOM_XIRAMGA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XIRAMGA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIRAMGA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XIRAMGA]

//>> GET_[QME_SCOM_XIRAMGA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XIRAMGA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIRAMGA;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XIRAMGA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XIRAMGA]

//>> PUT_[QME_SCOM_XIRAMGA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XIRAMGA(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMGA));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XIRAMGA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XIRAMGA]


//>> SET_[QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMGA));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR,
           QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR]

//>> SET_[QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMGA));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR,
           QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR]

//>> GET_[QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMGA));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR,
           QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR]

//>> SET_[QME_SCOM_XIRAMGA_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMGA_SPRG0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMGA));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMGA_SPRG0,
           QME_SCOM_XIRAMGA_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMGA_SPRG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMGA_SPRG0]

//>> SET_[QME_SCOM_XIRAMGA_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMGA_SPRG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMGA));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMGA_SPRG0,
           QME_SCOM_XIRAMGA_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMGA_SPRG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMGA_SPRG0]

//>> GET_[QME_SCOM_XIRAMGA_SPRG0]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMGA_SPRG0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMGA));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMGA_SPRG0,
           QME_SCOM_XIRAMGA_SPRG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMGA_SPRG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMGA_SPRG0]

//>> PREP_[QME_SCOM_XISIB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XISIB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XISIB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XISIB]

//>> GET_[QME_SCOM_XISIB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XISIB(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XISIB;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XISIB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XISIB]

//>> PUT_[QME_SCOM_XISIB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XISIB(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XISIB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XISIB]


//>> SET_[QME_SCOM_XISIB_ADDR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_ADDR,
           QME_SCOM_XISIB_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISIB_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_ADDR]

//>> SET_[QME_SCOM_XISIB_ADDR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_ADDR,
           QME_SCOM_XISIB_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISIB_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_ADDR]

//>> GET_[QME_SCOM_XISIB_ADDR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISIB_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.extractToRight<QME_SCOM_XISIB_ADDR,
           QME_SCOM_XISIB_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISIB_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_ADDR]

//>> SET_[QME_SCOM_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_R_NW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISIB_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_R_NW]

//>> SET_[QME_SCOM_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_R_NW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISIB_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_R_NW]

//>> SET_[QME_SCOM_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.setBit<QME_SCOM_XISIB_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XISIB_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_R_NW]

//>> CLEAR_[QME_SCOM_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XISIB_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.clearBit<QME_SCOM_XISIB_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XISIB_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XISIB_R_NW]

//>> GET_[QME_SCOM_XISIB_R_NW]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISIB_R_NW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.extractToRight<QME_SCOM_XISIB_R_NW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISIB_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_R_NW]

//>> GET_[QME_SCOM_XISIB_R_NW]
static inline bool GET_QME_SCOM_XISIB_R_NW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.getBit<QME_SCOM_XISIB_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XISIB_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_R_NW]

//>> SET_[QME_SCOM_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISIB_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_BUSY]

//>> SET_[QME_SCOM_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISIB_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_BUSY]

//>> SET_[QME_SCOM_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.setBit<QME_SCOM_XISIB_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XISIB_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_BUSY]

//>> CLEAR_[QME_SCOM_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XISIB_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.clearBit<QME_SCOM_XISIB_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XISIB_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XISIB_BUSY]

//>> GET_[QME_SCOM_XISIB_BUSY]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISIB_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.extractToRight<QME_SCOM_XISIB_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISIB_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_BUSY]

//>> GET_[QME_SCOM_XISIB_BUSY]
static inline bool GET_QME_SCOM_XISIB_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.getBit<QME_SCOM_XISIB_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XISIB_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_BUSY]

//>> SET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]

//>> SET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]

//>> SET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.setBit<QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.clearBit<QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]

//>> GET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.extractToRight<QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]

//>> GET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]
static inline bool GET_QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.getBit<QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING]

//>> SET_[QME_SCOM_XISIB_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_RSP_INFO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_RSP_INFO,
           QME_SCOM_XISIB_RSP_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISIB_RSP_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_RSP_INFO]

//>> SET_[QME_SCOM_XISIB_RSP_INFO]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_RSP_INFO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_RSP_INFO,
           QME_SCOM_XISIB_RSP_INFO_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISIB_RSP_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_RSP_INFO]

//>> GET_[QME_SCOM_XISIB_RSP_INFO]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISIB_RSP_INFO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.extractToRight<QME_SCOM_XISIB_RSP_INFO,
           QME_SCOM_XISIB_RSP_INFO_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISIB_RSP_INFO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_RSP_INFO]

//>> SET_[QME_SCOM_XISIB_RESET_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_RESET_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_RESET_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISIB_RESET_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_RESET_PENDING]

//>> SET_[QME_SCOM_XISIB_RESET_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_RESET_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_RESET_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISIB_RESET_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_RESET_PENDING]

//>> SET_[QME_SCOM_XISIB_RESET_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_RESET_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.setBit<QME_SCOM_XISIB_RESET_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XISIB_RESET_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_RESET_PENDING]

//>> CLEAR_[QME_SCOM_XISIB_RESET_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XISIB_RESET_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.clearBit<QME_SCOM_XISIB_RESET_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XISIB_RESET_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XISIB_RESET_PENDING]

//>> GET_[QME_SCOM_XISIB_RESET_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISIB_RESET_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.extractToRight<QME_SCOM_XISIB_RESET_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISIB_RESET_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_RESET_PENDING]

//>> GET_[QME_SCOM_XISIB_RESET_PENDING]
static inline bool GET_QME_SCOM_XISIB_RESET_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.getBit<QME_SCOM_XISIB_RESET_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XISIB_RESET_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_RESET_PENDING]

//>> SET_[QME_SCOM_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISIB_IFETCH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_IFETCH_PENDING]

//>> SET_[QME_SCOM_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_IFETCH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISIB_IFETCH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_IFETCH_PENDING]

//>> SET_[QME_SCOM_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_IFETCH_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.setBit<QME_SCOM_XISIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XISIB_IFETCH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_IFETCH_PENDING]

//>> CLEAR_[QME_SCOM_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XISIB_IFETCH_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.clearBit<QME_SCOM_XISIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XISIB_IFETCH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XISIB_IFETCH_PENDING]

//>> GET_[QME_SCOM_XISIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISIB_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.extractToRight<QME_SCOM_XISIB_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISIB_IFETCH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_IFETCH_PENDING]

//>> GET_[QME_SCOM_XISIB_IFETCH_PENDING]
static inline bool GET_QME_SCOM_XISIB_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.getBit<QME_SCOM_XISIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XISIB_IFETCH_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_IFETCH_PENDING]

//>> SET_[QME_SCOM_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XISIB_DATAOP_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_DATAOP_PENDING]

//>> SET_[QME_SCOM_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_DATAOP_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.insertFromRight<QME_SCOM_XISIB_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XISIB_DATAOP_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_DATAOP_PENDING]

//>> SET_[QME_SCOM_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XISIB_DATAOP_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.setBit<QME_SCOM_XISIB_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_SCOM_XISIB_DATAOP_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XISIB_DATAOP_PENDING]

//>> CLEAR_[QME_SCOM_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SCOM_XISIB_DATAOP_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return o_data.clearBit<QME_SCOM_XISIB_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_SCOM_XISIB_DATAOP_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SCOM_XISIB_DATAOP_PENDING]

//>> GET_[QME_SCOM_XISIB_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XISIB_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.extractToRight<QME_SCOM_XISIB_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XISIB_DATAOP_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_DATAOP_PENDING]

//>> GET_[QME_SCOM_XISIB_DATAOP_PENDING]
static inline bool GET_QME_SCOM_XISIB_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XISIB));
#endif
    return i_data.getBit<QME_SCOM_XISIB_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_SCOM_XISIB_DATAOP_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XISIB_DATAOP_PENDING]

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
    FAPI_ERR("0:scom_eq Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_eq Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_eq Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
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
