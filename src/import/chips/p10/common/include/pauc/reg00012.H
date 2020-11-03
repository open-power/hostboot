/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pauc/reg00012.H $         */
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

#ifndef __PAUC_REG00012_H_
#define __PAUC_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_DBG_MODE_REG_UNUSED]

//>> PREP_[PB_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PR0123_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PR0123_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PR0123_ERR]

//>> GET_[PB_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PR0123_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PR0123_ERR;
#endif
    return fapi2::getScom(i_target, PB_PR0123_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PR0123_ERR]

//>> PUT_[PB_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PR0123_ERR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return fapi2::putScom(i_target, PB_PR0123_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PR0123_ERR]


//>> SET_[PB_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_ADDRESS_PTY]

//>> CLEAR_[PB_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_ADDRESS_PTY]

//>> GET_[PB_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_ADDRESS_PTY]

//>> GET_[PB_PR0123_ERR_0_ADDRESS_PTY]
static inline bool GET_PB_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_ATAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_ATAG_PTY]

//>> GET_[PB_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_ATAG_PTY]

//>> GET_[PB_PR0123_ERR_0_ATAG_PTY]
static inline bool GET_PB_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC0_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_CC0_CREDITERR]
static inline bool GET_PB_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC1_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_CC1_CREDITERR]
static inline bool GET_PB_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC2_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_CC2_CREDITERR]
static inline bool GET_PB_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CC3_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_CC3_CREDITERR]
static inline bool GET_PB_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_CONTROL_ERROR]

//>> CLEAR_[PB_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PR0123_ERR_0_CONTROL_ERROR]
static inline bool GET_PB_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_DATA_PTY_ERR]

//>> CLEAR_[PB_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_DATA_PTY_ERR]

//>> GET_[PB_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_DATA_PTY_ERR]

//>> GET_[PB_PR0123_ERR_0_DATA_PTY_ERR]
static inline bool GET_PB_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]

//>> CLEAR_[PB_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]
static inline bool GET_PB_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_RTAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_RTAG_PTY]

//>> GET_[PB_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_RTAG_PTY]

//>> GET_[PB_PR0123_ERR_0_RTAG_PTY]
static inline bool GET_PB_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_TTAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_TTAG_PTY]

//>> GET_[PB_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_TTAG_PTY]

//>> GET_[PB_PR0123_ERR_0_TTAG_PTY]
static inline bool GET_PB_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_VC0_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_VC0_CREDITERR]
static inline bool GET_PB_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_VC1_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_0_VC1_CREDITERR]
static inline bool GET_PB_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_0_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_0_LINK_DOWN]

//>> CLEAR_[PB_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_0_LINK_DOWN]

//>> GET_[PB_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_0_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_LINK_DOWN]

//>> GET_[PB_PR0123_ERR_0_LINK_DOWN]
static inline bool GET_PB_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_ADDRESS_PTY]

//>> CLEAR_[PB_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_ADDRESS_PTY]

//>> GET_[PB_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_ADDRESS_PTY]

//>> GET_[PB_PR0123_ERR_1_ADDRESS_PTY]
static inline bool GET_PB_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_ATAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_ATAG_PTY]

//>> GET_[PB_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_ATAG_PTY]

//>> GET_[PB_PR0123_ERR_1_ATAG_PTY]
static inline bool GET_PB_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC0_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_CC0_CREDITERR]
static inline bool GET_PB_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC1_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_CC1_CREDITERR]
static inline bool GET_PB_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC2_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_CC2_CREDITERR]
static inline bool GET_PB_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CC3_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_CC3_CREDITERR]
static inline bool GET_PB_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_CONTROL_ERROR]

//>> CLEAR_[PB_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PR0123_ERR_1_CONTROL_ERROR]
static inline bool GET_PB_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_DATA_PTY_ERR]

//>> CLEAR_[PB_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_DATA_PTY_ERR]

//>> GET_[PB_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_DATA_PTY_ERR]

//>> GET_[PB_PR0123_ERR_1_DATA_PTY_ERR]
static inline bool GET_PB_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]

//>> CLEAR_[PB_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]
static inline bool GET_PB_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_RTAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_RTAG_PTY]

//>> GET_[PB_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_RTAG_PTY]

//>> GET_[PB_PR0123_ERR_1_RTAG_PTY]
static inline bool GET_PB_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_TTAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_TTAG_PTY]

//>> GET_[PB_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_TTAG_PTY]

//>> GET_[PB_PR0123_ERR_1_TTAG_PTY]
static inline bool GET_PB_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_VC0_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_VC0_CREDITERR]
static inline bool GET_PB_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_VC1_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_1_VC1_CREDITERR]
static inline bool GET_PB_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_1_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_1_LINK_DOWN]

//>> CLEAR_[PB_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_1_LINK_DOWN]

//>> GET_[PB_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_1_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_LINK_DOWN]

//>> GET_[PB_PR0123_ERR_1_LINK_DOWN]
static inline bool GET_PB_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_ADDRESS_PTY]

//>> CLEAR_[PB_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_ADDRESS_PTY]

//>> GET_[PB_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_ADDRESS_PTY]

//>> GET_[PB_PR0123_ERR_2_ADDRESS_PTY]
static inline bool GET_PB_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_ATAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_ATAG_PTY]

//>> GET_[PB_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_ATAG_PTY]

//>> GET_[PB_PR0123_ERR_2_ATAG_PTY]
static inline bool GET_PB_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC0_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_CC0_CREDITERR]
static inline bool GET_PB_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC1_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_CC1_CREDITERR]
static inline bool GET_PB_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC2_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_CC2_CREDITERR]
static inline bool GET_PB_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CC3_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_CC3_CREDITERR]
static inline bool GET_PB_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_CONTROL_ERROR]

//>> CLEAR_[PB_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PR0123_ERR_2_CONTROL_ERROR]
static inline bool GET_PB_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_DATA_PTY_ERR]

//>> CLEAR_[PB_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_DATA_PTY_ERR]

//>> GET_[PB_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_DATA_PTY_ERR]

//>> GET_[PB_PR0123_ERR_2_DATA_PTY_ERR]
static inline bool GET_PB_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]

//>> CLEAR_[PB_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]
static inline bool GET_PB_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_RTAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_RTAG_PTY]

//>> GET_[PB_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_RTAG_PTY]

//>> GET_[PB_PR0123_ERR_2_RTAG_PTY]
static inline bool GET_PB_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_TTAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_TTAG_PTY]

//>> GET_[PB_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_TTAG_PTY]

//>> GET_[PB_PR0123_ERR_2_TTAG_PTY]
static inline bool GET_PB_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_VC0_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_VC0_CREDITERR]
static inline bool GET_PB_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_VC1_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_2_VC1_CREDITERR]
static inline bool GET_PB_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_2_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_2_LINK_DOWN]

//>> CLEAR_[PB_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_2_LINK_DOWN]

//>> GET_[PB_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_2_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_LINK_DOWN]

//>> GET_[PB_PR0123_ERR_2_LINK_DOWN]
static inline bool GET_PB_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_ADDRESS_PTY]

//>> CLEAR_[PB_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_ADDRESS_PTY]

//>> GET_[PB_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_ADDRESS_PTY]

//>> GET_[PB_PR0123_ERR_3_ADDRESS_PTY]
static inline bool GET_PB_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_ATAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_ATAG_PTY]

//>> GET_[PB_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_ATAG_PTY]

//>> GET_[PB_PR0123_ERR_3_ATAG_PTY]
static inline bool GET_PB_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC0_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_CC0_CREDITERR]
static inline bool GET_PB_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC1_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_CC1_CREDITERR]
static inline bool GET_PB_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC2_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_CC2_CREDITERR]
static inline bool GET_PB_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CC3_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_CC3_CREDITERR]
static inline bool GET_PB_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_CONTROL_ERROR]

//>> CLEAR_[PB_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PR0123_ERR_3_CONTROL_ERROR]
static inline bool GET_PB_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_DATA_PTY_ERR]

//>> CLEAR_[PB_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_DATA_PTY_ERR]

//>> GET_[PB_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_DATA_PTY_ERR]

//>> GET_[PB_PR0123_ERR_3_DATA_PTY_ERR]
static inline bool GET_PB_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]

//>> CLEAR_[PB_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]
static inline bool GET_PB_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_RTAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_RTAG_PTY]

//>> GET_[PB_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_RTAG_PTY]

//>> GET_[PB_PR0123_ERR_3_RTAG_PTY]
static inline bool GET_PB_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_TTAG_PTY]

//>> CLEAR_[PB_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_TTAG_PTY]

//>> GET_[PB_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_TTAG_PTY]

//>> GET_[PB_PR0123_ERR_3_TTAG_PTY]
static inline bool GET_PB_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_VC0_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_VC0_CREDITERR]
static inline bool GET_PB_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_VC1_CREDITERR]

//>> CLEAR_[PB_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PR0123_ERR_3_VC1_CREDITERR]
static inline bool GET_PB_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PR0123_ERR_3_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_LINK_DOWN]

//>> SET_[PB_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.setBit<PB_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PR0123_ERR_3_LINK_DOWN]

//>> CLEAR_[PB_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PR0123_ERR_3_LINK_DOWN]

//>> GET_[PB_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PR0123_ERR_3_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_LINK_DOWN]

//>> GET_[PB_PR0123_ERR_3_LINK_DOWN]
static inline bool GET_PB_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PR0123_ERR));
#endif
    return i_data.getBit<PB_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PR0123_ERR_3_LINK_DOWN]

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
    FAPI_ERR("0:scom_pauc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_pauc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_pauc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_pauc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PCB_OPCG_STOP_PCB_OPCGSTOP]

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
    FAPI_ERR("0:scom_pauc Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_pauc Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_pauc Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
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
