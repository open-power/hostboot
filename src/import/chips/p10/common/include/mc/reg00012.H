/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mc/reg00012.H $           */
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

#ifndef __MC_REG00012_H_
#define __MC_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_0_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_1_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_2_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_3_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_4_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_5_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_6_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_7_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_8_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_9_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_10_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_11_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_12_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_13_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL2_14_PGOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_MASK0_ITR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_GLB_BRCST_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRIG_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("2:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("3:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("5:scom_mc Invalid dial access EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access EPS_DBG_MODE_REG_FREEZE_SEL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_ON chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_TRACE_RUN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access EPS_DBG_MODE_REG_IS_FROZEN_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS chip: %x, ec: %x", scomt::chip,
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
    FAPI_ERR("0:scom_mc Invalid dial access EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access EPS_DBG_MODE_REG_UNUSED chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access PCB_OPCG_STOP_PCB_OPCGSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access SCAN64CONTSCAN_SCAN64CONTSCAN_REG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN64CONTSCAN_SCAN64CONTSCAN_REG]

//>> PREP_[SCOMFIR_MCFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIRACT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCFIRACT0]

//>> GET_[SCOMFIR_MCFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIRACT0;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCFIRACT0]

//>> PUT_[SCOMFIR_MCFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFIRACT0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT0));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCFIRACT0]


//>> SET_[SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0,
           SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0]

//>> SET_[SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0,
           SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0]

//>> GET_[SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT0));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0,
           SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0]

//>> PREP_[SCOMFIR_MCMODE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCMODE0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCMODE0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCMODE0]

//>> GET_[SCOMFIR_MCMODE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCMODE0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCMODE0;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCMODE0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCMODE0]

//>> PUT_[SCOMFIR_MCMODE0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCMODE0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCMODE0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCMODE0]


//>> SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]

//>> CLEAR_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]
static inline bool GET_SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]

//>> CLEAR_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]
static inline bool GET_SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]

//>> CLEAR_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]
static inline bool GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]

//>> SET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]

//>> SET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]

//>> CLEAR_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]

//>> GET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]

//>> GET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]
static inline bool GET_SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_4]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_4]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_4]

//>> CLEAR_[SCOMFIR_MCMODE0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_RESERVED_4]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_4]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_4]
static inline bool GET_SCOMFIR_MCMODE0_RESERVED_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_4]

//>> SET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]

//>> SET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]

//>> SET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]

//>> CLEAR_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]

//>> GET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]

//>> GET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]
static inline bool GET_P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR]

//>> SET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]

//>> SET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]

//>> SET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]

//>> CLEAR_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]

//>> GET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]

//>> GET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]
static inline bool GET_SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID]

//>> SET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]

//>> SET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]

//>> SET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]

//>> CLEAR_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]

//>> GET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]

//>> GET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]
static inline bool GET_SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_7]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_7]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_7]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_7]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_7]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_7]

//>> CLEAR_[SCOMFIR_MCMODE0_RESERVED_7]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_RESERVED_7]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_7]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_7]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_7]
static inline bool GET_SCOMFIR_MCMODE0_RESERVED_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_7]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]

//>> CLEAR_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]
static inline bool GET_SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]

//>> CLEAR_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]
static inline bool GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]

//>> CLEAR_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]
static inline bool GET_SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_11]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_11]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_11]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_11]

//>> CLEAR_[SCOMFIR_MCMODE0_RESERVED_11]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_RESERVED_11]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_11]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_11]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_11]
static inline bool GET_SCOMFIR_MCMODE0_RESERVED_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_RESERVED_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_11]

//>> SET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]

//>> SET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]

//>> SET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]

//>> CLEAR_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]

//>> GET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]

//>> GET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]
static inline bool GET_P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCMODE0_HWFM_PERMANENT]

//>> SET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_DISABLE_MC_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]

//>> SET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_DISABLE_MC_SYNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]

//>> SET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_DISABLE_MC_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]

//>> CLEAR_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_DISABLE_MC_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]

//>> GET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_DISABLE_MC_SYNC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]

//>> GET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]
static inline bool GET_SCOMFIR_MCMODE0_DISABLE_MC_SYNC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_DISABLE_MC_SYNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_DISABLE_MC_SYNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_DISABLE_MC_SYNC]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_13]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_13]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_13]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_13]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_13]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_13]

//>> CLEAR_[SCOMFIR_MCMODE0_RESERVED_13]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_RESERVED_13]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_13]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_13]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_13]
static inline bool GET_SCOMFIR_MCMODE0_RESERVED_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_RESERVED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_13]

//>> SET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_64B_WR_IS_PWRT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]

//>> SET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_64B_WR_IS_PWRT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]

//>> SET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_64B_WR_IS_PWRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]

//>> CLEAR_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_64B_WR_IS_PWRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]

//>> GET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_64B_WR_IS_PWRT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]

//>> GET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]
static inline bool GET_SCOMFIR_MCMODE0_64B_WR_IS_PWRT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_64B_WR_IS_PWRT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_64B_WR_IS_PWRT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_64B_WR_IS_PWRT]

//>> SET_[SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE,
           SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE]

//>> SET_[SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE,
           SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE]

//>> GET_[SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE,
           SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_25_31]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_25_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_25_31,
           SCOMFIR_MCMODE0_RESERVED_25_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_25_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_25_31]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_25_31]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_25_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_25_31,
           SCOMFIR_MCMODE0_RESERVED_25_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_25_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_25_31]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_25_31]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_25_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_25_31,
           SCOMFIR_MCMODE0_RESERVED_25_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_25_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_25_31]

//>> SET_[SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY,
           SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY]

//>> SET_[SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY,
           SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY]

//>> GET_[SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY,
           SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY]

//>> SET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_MEM_MAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]

//>> SET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_MEM_MAP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_MEM_MAP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]

//>> SET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_MEM_MAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]

//>> CLEAR_[SCOMFIR_MCMODE0_MEM_MAP_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_MEM_MAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_MEM_MAP_MODE]

//>> GET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_MEM_MAP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]

//>> GET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]
static inline bool GET_SCOMFIR_MCMODE0_MEM_MAP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_MEM_MAP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_MEM_MAP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_MEM_MAP_MODE]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_37]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_37]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_37]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_37]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_37]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_37]

//>> CLEAR_[SCOMFIR_MCMODE0_RESERVED_37]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_RESERVED_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_RESERVED_37]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_37]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_37]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_37]
static inline bool GET_SCOMFIR_MCMODE0_RESERVED_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_37]

//>> SET_[SCOMFIR_MCMODE0_ADD_HASH_BITS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ADD_HASH_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ADD_HASH_BITS,
           SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_ADD_HASH_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ADD_HASH_BITS]

//>> SET_[SCOMFIR_MCMODE0_ADD_HASH_BITS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ADD_HASH_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ADD_HASH_BITS,
           SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_ADD_HASH_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ADD_HASH_BITS]

//>> GET_[SCOMFIR_MCMODE0_ADD_HASH_BITS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ADD_HASH_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ADD_HASH_BITS,
           SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_ADD_HASH_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ADD_HASH_BITS]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_ADD_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_ENABLE_ADD_HASH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]

//>> SET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.setBit<SCOMFIR_MCMODE0_ENABLE_ADD_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]

//>> CLEAR_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE0_ENABLE_ADD_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_ENABLE_ADD_HASH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]

//>> GET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]
static inline bool GET_SCOMFIR_MCMODE0_ENABLE_ADD_HASH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.getBit<SCOMFIR_MCMODE0_ENABLE_ADD_HASH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE0_ENABLE_ADD_HASH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_ENABLE_ADD_HASH]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_41_63]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_41_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_41_63,
           SCOMFIR_MCMODE0_RESERVED_41_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_41_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_41_63]

//>> SET_[SCOMFIR_MCMODE0_RESERVED_41_63]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE0_RESERVED_41_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE0_RESERVED_41_63,
           SCOMFIR_MCMODE0_RESERVED_41_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_41_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE0_RESERVED_41_63]

//>> GET_[SCOMFIR_MCMODE0_RESERVED_41_63]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE0_RESERVED_41_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE0));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE0_RESERVED_41_63,
           SCOMFIR_MCMODE0_RESERVED_41_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE0_RESERVED_41_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE0_RESERVED_41_63]

//>> PREP_[SCOMFIR_MCPERF1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCPERF1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCPERF1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCPERF1]

//>> GET_[SCOMFIR_MCPERF1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCPERF1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCPERF1;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCPERF1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCPERF1]

//>> PUT_[SCOMFIR_MCPERF1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCPERF1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCPERF1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCPERF1]


//>> SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]

//>> CLEAR_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]

//>> GET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]

//>> GET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]
static inline bool GET_SCOMFIR_MCPERF1_DISABLE_FASTPATH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]

//>> CLEAR_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]

//>> GET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]

//>> GET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]
static inline bool GET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]

//>> CLEAR_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]

//>> GET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]

//>> GET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]
static inline bool GET_SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]

//>> CLEAR_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]

//>> GET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]

//>> GET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]
static inline bool GET_SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]

//>> CLEAR_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]

//>> GET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]

//>> GET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]
static inline bool GET_SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]

//>> SET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]

//>> CLEAR_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]

//>> GET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]

//>> GET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]
static inline bool GET_SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT]

//>> SET_[SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK,
           SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK]

//>> SET_[SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK,
           SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK]

//>> GET_[SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK,
           SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK]

//>> SET_[SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH,
           SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH]

//>> SET_[SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH,
           SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH]

//>> GET_[SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH,
           SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH]

//>> SET_[SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT,
           SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT]

//>> SET_[SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT,
           SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT]

//>> GET_[SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT,
           SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]

//>> CLEAR_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]

//>> GET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]

//>> GET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]
static inline bool GET_SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]

//>> SET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]

//>> CLEAR_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]

//>> GET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]

//>> GET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]
static inline bool GET_SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE]

//>> SET_[SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH,
           SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH]

//>> SET_[SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH,
           SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH]

//>> GET_[SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH,
           SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH]

//>> SET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE]

//>> SET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE]

//>> GET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE]

//>> SET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE]

//>> SET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE]

//>> GET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE,
           SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE]

//>> SET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]

//>> SET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]

//>> SET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]

//>> CLEAR_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]

//>> GET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]

//>> GET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]
static inline bool GET_SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD]

//>> SET_[SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE,
           SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE]

//>> SET_[SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE,
           SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE]

//>> GET_[SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE,
           SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE]

//>> SET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]

//>> SET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]

//>> SET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]

//>> CLEAR_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]

//>> GET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]

//>> GET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]
static inline bool GET_SCOMFIR_MCPERF1_EN_NONSPEC_EDATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_EN_NONSPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_NONSPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_EN_NONSPEC_EDATA]

//>> SET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_SPEC_EDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]

//>> SET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_SPEC_EDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]

//>> SET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_EN_SPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]

//>> CLEAR_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_EN_SPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]

//>> GET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_EN_SPEC_EDATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]

//>> GET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]
static inline bool GET_SCOMFIR_MCPERF1_EN_SPEC_EDATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_EN_SPEC_EDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_SPEC_EDATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_EN_SPEC_EDATA]

//>> SET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]

//>> SET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]

//>> SET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]

//>> CLEAR_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]

//>> GET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]

//>> GET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]
static inline bool GET_SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR]

//>> SET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_VG_SPECDIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]

//>> SET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_EN_VG_SPECDIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]

//>> SET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.setBit<SCOMFIR_MCPERF1_EN_VG_SPECDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]

//>> CLEAR_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.clearBit<SCOMFIR_MCPERF1_EN_VG_SPECDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]

//>> GET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_EN_VG_SPECDIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]

//>> GET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]
static inline bool GET_SCOMFIR_MCPERF1_EN_VG_SPECDIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.getBit<SCOMFIR_MCPERF1_EN_VG_SPECDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCPERF1_EN_VG_SPECDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_EN_VG_SPECDIS]

//>> SET_[SCOMFIR_MCPERF1_RESERVED_47_63]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_RESERVED_47_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_RESERVED_47_63,
           SCOMFIR_MCPERF1_RESERVED_47_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCPERF1_RESERVED_47_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_RESERVED_47_63]

//>> SET_[SCOMFIR_MCPERF1_RESERVED_47_63]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCPERF1_RESERVED_47_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCPERF1_RESERVED_47_63,
           SCOMFIR_MCPERF1_RESERVED_47_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCPERF1_RESERVED_47_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCPERF1_RESERVED_47_63]

//>> GET_[SCOMFIR_MCPERF1_RESERVED_47_63]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCPERF1_RESERVED_47_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCPERF1));
#endif
    return i_data.extractToRight<SCOMFIR_MCPERF1_RESERVED_47_63,
           SCOMFIR_MCPERF1_RESERVED_47_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCPERF1_RESERVED_47_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCPERF1_RESERVED_47_63]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
