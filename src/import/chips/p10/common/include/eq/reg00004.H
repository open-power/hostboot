/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/eq/reg00004.H $           */
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

#ifndef __EQ_REG00004_H_
#define __EQ_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> PREP_[CLOCK_STAT_ARY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLOCK_STAT_ARY(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLOCK_STAT_ARY;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLOCK_STAT_ARY]

//>> GET_[CLOCK_STAT_ARY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLOCK_STAT_ARY(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLOCK_STAT_ARY;
#endif
    return fapi2::getScom(i_target, CLOCK_STAT_ARY, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLOCK_STAT_ARY]

//>> PUT_[CLOCK_STAT_ARY]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLOCK_STAT_ARY(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return fapi2::putScom(i_target, CLOCK_STAT_ARY, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLOCK_STAT_ARY]


//>> SET_[CLOCK_STAT_ARY_PERV_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_PERV_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_PERV_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_PERV_ARY]

//>> SET_[CLOCK_STAT_ARY_PERV_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_PERV_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_PERV_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_PERV_ARY]

//>> SET_[CLOCK_STAT_ARY_PERV_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_PERV_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_PERV_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_PERV_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_PERV_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_PERV_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_PERV_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_PERV_ARY]

//>> GET_[CLOCK_STAT_ARY_PERV_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_PERV_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_PERV_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_PERV_ARY]

//>> GET_[CLOCK_STAT_ARY_PERV_ARY]
static inline bool GET_CLOCK_STAT_ARY_PERV_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_PERV_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_PERV_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_PERV_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT1_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT1_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT1_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT1_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT1_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT1_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT1_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT1_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT1_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT1_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT1_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT1_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT1_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT1_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT1_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT1_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT1_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT1_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT1_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT1_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT1_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT1_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT1_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT1_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT1_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT2_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT2_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT2_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT2_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT2_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT2_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT2_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT2_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT2_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT2_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT2_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT2_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT2_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT2_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT2_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT2_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT2_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT2_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT2_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT2_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT2_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT2_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT2_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT2_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT2_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT3_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT3_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT3_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT3_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT3_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT3_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT3_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT3_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT3_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT3_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT3_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT3_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT3_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT3_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT3_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT3_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT3_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT3_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT3_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT3_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT3_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT3_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT3_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT3_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT3_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT4_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT4_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT4_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT4_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT4_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT4_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT4_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT4_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT4_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT4_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT4_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT4_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT4_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT4_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT4_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT4_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT4_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT4_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT4_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT4_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT4_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT4_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT4_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT4_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT4_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT5_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT5_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT5_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT5_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT5_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT5_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT5_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT5_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT5_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT5_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT5_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT5_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT5_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT5_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT5_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT5_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT5_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT5_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT5_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT5_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT5_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT5_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT5_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT5_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT5_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT6_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT6_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT6_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT6_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT6_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT6_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT6_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT6_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT6_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT6_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT6_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT6_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT6_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT6_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT6_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT6_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT6_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT6_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT6_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT6_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT6_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT6_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT6_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT6_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT6_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT7_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT7_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT7_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT7_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT7_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT7_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT7_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT7_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT7_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT7_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT7_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT7_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT7_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT7_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT7_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT7_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT7_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT7_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT7_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT7_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT7_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT7_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT7_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT7_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT7_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT8_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT8_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT8_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT8_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT8_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT8_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT8_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT8_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT8_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT8_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT8_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT8_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT8_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT8_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT8_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT8_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT8_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT8_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT8_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT8_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT8_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT8_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT8_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT8_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT8_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT9_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT9_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT9_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT9_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT9_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT9_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT9_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT9_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT9_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT9_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT9_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT9_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT9_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT9_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT9_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT9_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT9_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT9_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT9_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT9_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT9_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT9_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT9_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT9_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT9_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT10_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT10_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT10_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT10_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT10_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT10_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT10_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT10_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT10_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT10_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT10_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT10_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT10_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT10_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT10_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT10_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT10_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT10_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT10_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT10_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT10_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT10_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT10_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT10_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT10_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT11_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT11_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT11_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT11_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT11_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT11_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT11_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT11_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT11_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT11_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT11_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT11_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT11_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT11_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT11_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT11_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT11_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT11_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT11_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT11_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT11_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT11_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT11_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT11_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT11_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT12_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT12_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT12_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT12_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT12_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT12_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT12_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT12_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT12_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT12_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT12_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT12_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT12_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT12_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT12_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT12_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT12_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT12_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT12_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT12_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT12_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT12_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT12_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT12_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT12_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT13_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT13_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT13_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT13_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT13_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT13_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT13_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT13_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT13_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT13_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT13_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT13_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT13_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT13_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT13_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT13_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT13_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT13_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT13_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT13_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT13_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT13_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT13_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT13_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT13_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT14_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT14_ARY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT14_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT14_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT14_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT14_ARY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.insertFromRight<CLOCK_STAT_ARY_UNIT14_ARY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT14_ARY]

//>> SET_[CLOCK_STAT_ARY_UNIT14_ARY]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_ARY_UNIT14_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.setBit<CLOCK_STAT_ARY_UNIT14_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_ARY_UNIT14_ARY]

//>> CLEAR_[CLOCK_STAT_ARY_UNIT14_ARY]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_ARY_UNIT14_ARY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return o_data.clearBit<CLOCK_STAT_ARY_UNIT14_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_ARY_UNIT14_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT14_ARY]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_ARY_UNIT14_ARY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.extractToRight<CLOCK_STAT_ARY_UNIT14_ARY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT14_ARY]

//>> GET_[CLOCK_STAT_ARY_UNIT14_ARY]
static inline bool GET_CLOCK_STAT_ARY_UNIT14_ARY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_ARY));
#endif
    return i_data.getBit<CLOCK_STAT_ARY_UNIT14_ARY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CLOCK_STAT_ARY_UNIT14_ARY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_ARY_UNIT14_ARY]

//>> PREP_[OPCG_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_REG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_REG2]

//>> GET_[OPCG_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_REG2(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_REG2;
#endif
    return fapi2::getScom(i_target, OPCG_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_REG2]

//>> PUT_[OPCG_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_REG2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return fapi2::putScom(i_target, OPCG_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_REG2]


//>> SET_[OPCG_REG2_OPCG_GO2]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_OPCG_GO2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_OPCG_GO2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_OPCG_GO2]

//>> SET_[OPCG_REG2_OPCG_GO2]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_OPCG_GO2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_OPCG_GO2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_OPCG_GO2]

//>> SET_[OPCG_REG2_OPCG_GO2]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_OPCG_GO2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.setBit<OPCG_REG2_OPCG_GO2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_OPCG_GO2]

//>> CLEAR_[OPCG_REG2_OPCG_GO2]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG2_OPCG_GO2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.clearBit<OPCG_REG2_OPCG_GO2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG2_OPCG_GO2]

//>> GET_[OPCG_REG2_OPCG_GO2]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_OPCG_GO2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_OPCG_GO2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_OPCG_GO2]

//>> GET_[OPCG_REG2_OPCG_GO2]
static inline bool GET_OPCG_REG2_OPCG_GO2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.getBit<OPCG_REG2_OPCG_GO2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG2_OPCG_GO2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_OPCG_GO2]

//>> SET_[OPCG_REG2_PRPG_WEIGHTING]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_WEIGHTING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_WEIGHTING,
           OPCG_REG2_PRPG_WEIGHTING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_PRPG_WEIGHTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_WEIGHTING]

//>> SET_[OPCG_REG2_PRPG_WEIGHTING]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_WEIGHTING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_WEIGHTING,
           OPCG_REG2_PRPG_WEIGHTING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_PRPG_WEIGHTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_WEIGHTING]

//>> GET_[OPCG_REG2_PRPG_WEIGHTING]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_PRPG_WEIGHTING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_PRPG_WEIGHTING,
           OPCG_REG2_PRPG_WEIGHTING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_PRPG_WEIGHTING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_PRPG_WEIGHTING]

//>> SET_[OPCG_REG2_PRPG_SEED]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_SEED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_SEED,
           OPCG_REG2_PRPG_SEED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_PRPG_SEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_SEED]

//>> SET_[OPCG_REG2_PRPG_SEED]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_SEED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_SEED,
           OPCG_REG2_PRPG_SEED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_PRPG_SEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_SEED]

//>> GET_[OPCG_REG2_PRPG_SEED]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_PRPG_SEED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_PRPG_SEED,
           OPCG_REG2_PRPG_SEED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_PRPG_SEED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_PRPG_SEED]

//>> SET_[OPCG_REG2_PRPG_A_VAL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_A_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_A_VAL,
           OPCG_REG2_PRPG_A_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_PRPG_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_A_VAL]

//>> SET_[OPCG_REG2_PRPG_A_VAL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_A_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_A_VAL,
           OPCG_REG2_PRPG_A_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_PRPG_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_A_VAL]

//>> GET_[OPCG_REG2_PRPG_A_VAL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_PRPG_A_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_PRPG_A_VAL,
           OPCG_REG2_PRPG_A_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_PRPG_A_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_PRPG_A_VAL]

//>> SET_[OPCG_REG2_PRPG_B_VAL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_B_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_B_VAL,
           OPCG_REG2_PRPG_B_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_PRPG_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_B_VAL]

//>> SET_[OPCG_REG2_PRPG_B_VAL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_B_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_B_VAL,
           OPCG_REG2_PRPG_B_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_PRPG_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_B_VAL]

//>> GET_[OPCG_REG2_PRPG_B_VAL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_PRPG_B_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_PRPG_B_VAL,
           OPCG_REG2_PRPG_B_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_PRPG_B_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_PRPG_B_VAL]

//>> SET_[OPCG_REG2_PRPG_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_MODE]

//>> SET_[OPCG_REG2_PRPG_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_PRPG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_MODE]

//>> SET_[OPCG_REG2_PRPG_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_PRPG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.setBit<OPCG_REG2_PRPG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_PRPG_MODE]

//>> CLEAR_[OPCG_REG2_PRPG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG2_PRPG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.clearBit<OPCG_REG2_PRPG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG2_PRPG_MODE]

//>> GET_[OPCG_REG2_PRPG_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_PRPG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_PRPG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_PRPG_MODE]

//>> GET_[OPCG_REG2_PRPG_MODE]
static inline bool GET_OPCG_REG2_PRPG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.getBit<OPCG_REG2_PRPG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG2_PRPG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_PRPG_MODE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM,
           OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM,
           OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM,
           OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK,
           OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK,
           OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK,
           OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.setBit<OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]

//>> CLEAR_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.clearBit<OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]
static inline bool GET_OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.getBit<OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.setBit<OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]

//>> CLEAR_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.clearBit<OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]
static inline bool GET_OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.getBit<OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.setBit<OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]

//>> CLEAR_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.clearBit<OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]
static inline bool GET_OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.getBit<OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.setBit<OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]

//>> CLEAR_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.clearBit<OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]
static inline bool GET_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.getBit<OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT,
           OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT]

//>> SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return o_data.insertFromRight<OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT,
           OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT]

//>> GET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG2));
#endif
    return i_data.extractToRight<OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT,
           OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT]

//>> PREP_[QME_EISTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_EISTR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EISTR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_EISTR]

//>> GET_[QME_EISTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_EISTR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_EISTR;
#endif
    return fapi2::getScom(i_target, QME_EISTR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_EISTR]

//>> PUT_[QME_EISTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_EISTR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_EISTR));
#endif
    return fapi2::putScom(i_target, QME_EISTR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_EISTR]


//>> SET_[QME_EISTR_INTERRUPT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_QME_EISTR_INTERRUPT_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISTR));
#endif
    return o_data.insertFromRight<QME_EISTR_INTERRUPT_STATUS,
           QME_EISTR_INTERRUPT_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_EISTR_INTERRUPT_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISTR_INTERRUPT_STATUS]

//>> SET_[QME_EISTR_INTERRUPT_STATUS]
static inline fapi2::buffer<uint64_t>& SET_QME_EISTR_INTERRUPT_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISTR));
#endif
    return o_data.insertFromRight<QME_EISTR_INTERRUPT_STATUS,
           QME_EISTR_INTERRUPT_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_EISTR_INTERRUPT_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_EISTR_INTERRUPT_STATUS]

//>> GET_[QME_EISTR_INTERRUPT_STATUS]
static inline fapi2::buffer<uint64_t>& GET_QME_EISTR_INTERRUPT_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_EISTR));
#endif
    return i_data.extractToRight<QME_EISTR_INTERRUPT_STATUS,
           QME_EISTR_INTERRUPT_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_EISTR_INTERRUPT_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_EISTR_INTERRUPT_STATUS]

//>> PREP_[QME_FTXR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_FTXR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_FTXR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_FTXR]

//>> GET_[QME_FTXR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_FTXR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_FTXR;
#endif
    return fapi2::getScom(i_target, QME_FTXR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_FTXR]

//>> PUT_[QME_FTXR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_FTXR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return fapi2::putScom(i_target, QME_FTXR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_FTXR]


//>> SET_[QME_FTXR_C0_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_C0_DTC_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_C0_DTC_INDEX,
           QME_FTXR_C0_DTC_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_FTXR_C0_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_C0_DTC_INDEX]

//>> SET_[QME_FTXR_C0_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_C0_DTC_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_C0_DTC_INDEX,
           QME_FTXR_C0_DTC_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_FTXR_C0_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_C0_DTC_INDEX]

//>> GET_[QME_FTXR_C0_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_FTXR_C0_DTC_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return i_data.extractToRight<QME_FTXR_C0_DTC_INDEX,
           QME_FTXR_C0_DTC_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_FTXR_C0_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_FTXR_C0_DTC_INDEX]

//>> SET_[QME_FTXR_C1_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_C1_DTC_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_C1_DTC_INDEX,
           QME_FTXR_C1_DTC_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_FTXR_C1_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_C1_DTC_INDEX]

//>> SET_[QME_FTXR_C1_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_C1_DTC_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_C1_DTC_INDEX,
           QME_FTXR_C1_DTC_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_FTXR_C1_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_C1_DTC_INDEX]

//>> GET_[QME_FTXR_C1_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_FTXR_C1_DTC_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return i_data.extractToRight<QME_FTXR_C1_DTC_INDEX,
           QME_FTXR_C1_DTC_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_FTXR_C1_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_FTXR_C1_DTC_INDEX]

//>> SET_[QME_FTXR_C2_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_C2_DTC_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_C2_DTC_INDEX,
           QME_FTXR_C2_DTC_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_FTXR_C2_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_C2_DTC_INDEX]

//>> SET_[QME_FTXR_C2_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_C2_DTC_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_C2_DTC_INDEX,
           QME_FTXR_C2_DTC_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_FTXR_C2_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_C2_DTC_INDEX]

//>> GET_[QME_FTXR_C2_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_FTXR_C2_DTC_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return i_data.extractToRight<QME_FTXR_C2_DTC_INDEX,
           QME_FTXR_C2_DTC_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_FTXR_C2_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_FTXR_C2_DTC_INDEX]

//>> SET_[QME_FTXR_C3_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_C3_DTC_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_C3_DTC_INDEX,
           QME_FTXR_C3_DTC_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_FTXR_C3_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_C3_DTC_INDEX]

//>> SET_[QME_FTXR_C3_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_C3_DTC_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_C3_DTC_INDEX,
           QME_FTXR_C3_DTC_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_FTXR_C3_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_C3_DTC_INDEX]

//>> GET_[QME_FTXR_C3_DTC_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_FTXR_C3_DTC_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return i_data.extractToRight<QME_FTXR_C3_DTC_INDEX,
           QME_FTXR_C3_DTC_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_FTXR_C3_DTC_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_FTXR_C3_DTC_INDEX]

//>> SET_[QME_FTXR_FTX_UPDATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_FTX_UPDATE_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_FTX_UPDATE_PENDING,
           QME_FTXR_FTX_UPDATE_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_FTXR_FTX_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_FTX_UPDATE_PENDING]

//>> SET_[QME_FTXR_FTX_UPDATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_FTX_UPDATE_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_FTX_UPDATE_PENDING,
           QME_FTXR_FTX_UPDATE_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_FTXR_FTX_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_FTX_UPDATE_PENDING]

//>> GET_[QME_FTXR_FTX_UPDATE_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_FTXR_FTX_UPDATE_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return i_data.extractToRight<QME_FTXR_FTX_UPDATE_PENDING,
           QME_FTXR_FTX_UPDATE_PENDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_FTXR_FTX_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_FTXR_FTX_UPDATE_PENDING]

//>> SET_[QME_FTXR_QOS_UPDATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_QOS_UPDATE_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_QOS_UPDATE_PENDING,
           QME_FTXR_QOS_UPDATE_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_FTXR_QOS_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_QOS_UPDATE_PENDING]

//>> SET_[QME_FTXR_QOS_UPDATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_QME_FTXR_QOS_UPDATE_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return o_data.insertFromRight<QME_FTXR_QOS_UPDATE_PENDING,
           QME_FTXR_QOS_UPDATE_PENDING_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_FTXR_QOS_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_FTXR_QOS_UPDATE_PENDING]

//>> GET_[QME_FTXR_QOS_UPDATE_PENDING]
static inline fapi2::buffer<uint64_t>& GET_QME_FTXR_QOS_UPDATE_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_FTXR));
#endif
    return i_data.extractToRight<QME_FTXR_QOS_UPDATE_PENDING,
           QME_FTXR_QOS_UPDATE_PENDING_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_FTXR_QOS_UPDATE_PENDING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_FTXR_QOS_UPDATE_PENDING]

//>> PREP_[QME_LFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_LFIRACT0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRACT0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_LFIRACT0]

//>> GET_[QME_LFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_LFIRACT0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_LFIRACT0;
#endif
    return fapi2::getScom(i_target, QME_LFIRACT0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_LFIRACT0]

//>> PUT_[QME_LFIRACT0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_LFIRACT0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_LFIRACT0));
#endif
    return fapi2::putScom(i_target, QME_LFIRACT0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_LFIRACT0]


//>> SET_[QME_LFIRACT0_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_QME_LFIRACT0_FIR_ACTION0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_LFIRACT0));
#endif
    return o_data.insertFromRight<QME_LFIRACT0_FIR_ACTION0,
           QME_LFIRACT0_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_LFIRACT0_FIR_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_LFIRACT0_FIR_ACTION0]

//>> SET_[QME_LFIRACT0_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_QME_LFIRACT0_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_LFIRACT0));
#endif
    return o_data.insertFromRight<QME_LFIRACT0_FIR_ACTION0,
           QME_LFIRACT0_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_LFIRACT0_FIR_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_LFIRACT0_FIR_ACTION0]

//>> GET_[QME_LFIRACT0_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& GET_QME_LFIRACT0_FIR_ACTION0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_LFIRACT0));
#endif
    return i_data.extractToRight<QME_LFIRACT0_FIR_ACTION0,
           QME_LFIRACT0_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_LFIRACT0_FIR_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_LFIRACT0_FIR_ACTION0]

//>> PREP_[QME_PLSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PLSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PLSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PLSR]

//>> GET_[QME_PLSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PLSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PLSR;
#endif
    return fapi2::getScom(i_target, QME_PLSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PLSR]

//>> PUT_[QME_PLSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PLSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return fapi2::putScom(i_target, QME_PLSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PLSR]


//>> SET_[QME_PLSR_0_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_0_T0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_0_T0,
           QME_PLSR_0_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_0_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_0_T0]

//>> SET_[QME_PLSR_0_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_0_T0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_0_T0,
           QME_PLSR_0_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_0_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_0_T0]

//>> GET_[QME_PLSR_0_T0]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_0_T0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_0_T0,
           QME_PLSR_0_T0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_0_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_0_T0]

//>> SET_[QME_PLSR_0_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_0_T1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_0_T1,
           QME_PLSR_0_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_0_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_0_T1]

//>> SET_[QME_PLSR_0_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_0_T1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_0_T1,
           QME_PLSR_0_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_0_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_0_T1]

//>> GET_[QME_PLSR_0_T1]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_0_T1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_0_T1,
           QME_PLSR_0_T1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_0_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_0_T1]

//>> SET_[QME_PLSR_0_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_0_T2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_0_T2,
           QME_PLSR_0_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_0_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_0_T2]

//>> SET_[QME_PLSR_0_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_0_T2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_0_T2,
           QME_PLSR_0_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_0_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_0_T2]

//>> GET_[QME_PLSR_0_T2]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_0_T2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_0_T2,
           QME_PLSR_0_T2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_0_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_0_T2]

//>> SET_[QME_PLSR_0_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_0_T3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_0_T3,
           QME_PLSR_0_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_0_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_0_T3]

//>> SET_[QME_PLSR_0_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_0_T3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_0_T3,
           QME_PLSR_0_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_0_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_0_T3]

//>> GET_[QME_PLSR_0_T3]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_0_T3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_0_T3,
           QME_PLSR_0_T3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_0_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_0_T3]

//>> SET_[QME_PLSR_1_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_1_T0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_1_T0,
           QME_PLSR_1_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_1_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_1_T0]

//>> SET_[QME_PLSR_1_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_1_T0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_1_T0,
           QME_PLSR_1_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_1_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_1_T0]

//>> GET_[QME_PLSR_1_T0]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_1_T0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_1_T0,
           QME_PLSR_1_T0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_1_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_1_T0]

//>> SET_[QME_PLSR_1_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_1_T1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_1_T1,
           QME_PLSR_1_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_1_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_1_T1]

//>> SET_[QME_PLSR_1_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_1_T1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_1_T1,
           QME_PLSR_1_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_1_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_1_T1]

//>> GET_[QME_PLSR_1_T1]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_1_T1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_1_T1,
           QME_PLSR_1_T1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_1_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_1_T1]

//>> SET_[QME_PLSR_1_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_1_T2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_1_T2,
           QME_PLSR_1_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_1_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_1_T2]

//>> SET_[QME_PLSR_1_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_1_T2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_1_T2,
           QME_PLSR_1_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_1_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_1_T2]

//>> GET_[QME_PLSR_1_T2]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_1_T2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_1_T2,
           QME_PLSR_1_T2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_1_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_1_T2]

//>> SET_[QME_PLSR_1_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_1_T3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_1_T3,
           QME_PLSR_1_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_1_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_1_T3]

//>> SET_[QME_PLSR_1_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_1_T3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_1_T3,
           QME_PLSR_1_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_1_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_1_T3]

//>> GET_[QME_PLSR_1_T3]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_1_T3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_1_T3,
           QME_PLSR_1_T3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_1_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_1_T3]

//>> SET_[QME_PLSR_2_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_2_T0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_2_T0,
           QME_PLSR_2_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_2_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_2_T0]

//>> SET_[QME_PLSR_2_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_2_T0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_2_T0,
           QME_PLSR_2_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_2_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_2_T0]

//>> GET_[QME_PLSR_2_T0]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_2_T0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_2_T0,
           QME_PLSR_2_T0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_2_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_2_T0]

//>> SET_[QME_PLSR_2_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_2_T1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_2_T1,
           QME_PLSR_2_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_2_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_2_T1]

//>> SET_[QME_PLSR_2_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_2_T1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_2_T1,
           QME_PLSR_2_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_2_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_2_T1]

//>> GET_[QME_PLSR_2_T1]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_2_T1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_2_T1,
           QME_PLSR_2_T1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_2_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_2_T1]

//>> SET_[QME_PLSR_2_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_2_T2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_2_T2,
           QME_PLSR_2_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_2_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_2_T2]

//>> SET_[QME_PLSR_2_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_2_T2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_2_T2,
           QME_PLSR_2_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_2_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_2_T2]

//>> GET_[QME_PLSR_2_T2]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_2_T2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_2_T2,
           QME_PLSR_2_T2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_2_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_2_T2]

//>> SET_[QME_PLSR_2_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_2_T3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_2_T3,
           QME_PLSR_2_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_2_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_2_T3]

//>> SET_[QME_PLSR_2_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_2_T3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_2_T3,
           QME_PLSR_2_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_2_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_2_T3]

//>> GET_[QME_PLSR_2_T3]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_2_T3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_2_T3,
           QME_PLSR_2_T3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_2_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_2_T3]

//>> SET_[QME_PLSR_3_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_3_T0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_3_T0,
           QME_PLSR_3_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_3_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_3_T0]

//>> SET_[QME_PLSR_3_T0]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_3_T0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_3_T0,
           QME_PLSR_3_T0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_3_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_3_T0]

//>> GET_[QME_PLSR_3_T0]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_3_T0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_3_T0,
           QME_PLSR_3_T0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_3_T0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_3_T0]

//>> SET_[QME_PLSR_3_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_3_T1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_3_T1,
           QME_PLSR_3_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_3_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_3_T1]

//>> SET_[QME_PLSR_3_T1]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_3_T1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_3_T1,
           QME_PLSR_3_T1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_3_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_3_T1]

//>> GET_[QME_PLSR_3_T1]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_3_T1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_3_T1,
           QME_PLSR_3_T1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_3_T1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_3_T1]

//>> SET_[QME_PLSR_3_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_3_T2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_3_T2,
           QME_PLSR_3_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_3_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_3_T2]

//>> SET_[QME_PLSR_3_T2]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_3_T2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_3_T2,
           QME_PLSR_3_T2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_3_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_3_T2]

//>> GET_[QME_PLSR_3_T2]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_3_T2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_3_T2,
           QME_PLSR_3_T2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_3_T2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_3_T2]

//>> SET_[QME_PLSR_3_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_3_T3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_3_T3,
           QME_PLSR_3_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PLSR_3_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_3_T3]

//>> SET_[QME_PLSR_3_T3]
static inline fapi2::buffer<uint64_t>& SET_QME_PLSR_3_T3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return o_data.insertFromRight<QME_PLSR_3_T3,
           QME_PLSR_3_T3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PLSR_3_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PLSR_3_T3]

//>> GET_[QME_PLSR_3_T3]
static inline fapi2::buffer<uint64_t>& GET_QME_PLSR_3_T3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PLSR));
#endif
    return i_data.extractToRight<QME_PLSR_3_T3,
           QME_PLSR_3_T3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PLSR_3_T3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PLSR_3_T3]

//>> PREP_[QME_QHB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_QHB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QHB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_QHB]

//>> GET_[QME_QHB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_QHB(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QHB;
#endif
    return fapi2::getScom(i_target, QME_QHB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_QHB]

//>> PUT_[QME_QHB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_QHB(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return fapi2::putScom(i_target, QME_QHB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_QHB]


//>> SET_[QME_QHB_HEARTBEAT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_QME_QHB_HEARTBEAT_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.insertFromRight<QME_QHB_HEARTBEAT_COUNT,
           QME_QHB_HEARTBEAT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QHB_HEARTBEAT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHB_HEARTBEAT_COUNT]

//>> SET_[QME_QHB_HEARTBEAT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_QME_QHB_HEARTBEAT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.insertFromRight<QME_QHB_HEARTBEAT_COUNT,
           QME_QHB_HEARTBEAT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QHB_HEARTBEAT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHB_HEARTBEAT_COUNT]

//>> GET_[QME_QHB_HEARTBEAT_COUNT]
static inline fapi2::buffer<uint64_t>& GET_QME_QHB_HEARTBEAT_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return i_data.extractToRight<QME_QHB_HEARTBEAT_COUNT,
           QME_QHB_HEARTBEAT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QHB_HEARTBEAT_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHB_HEARTBEAT_COUNT]

//>> SET_[QME_QHB_HEARTBEAT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHB_HEARTBEAT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.insertFromRight<QME_QHB_HEARTBEAT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QHB_HEARTBEAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHB_HEARTBEAT_ENABLE]

//>> SET_[QME_QHB_HEARTBEAT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHB_HEARTBEAT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.insertFromRight<QME_QHB_HEARTBEAT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QHB_HEARTBEAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHB_HEARTBEAT_ENABLE]

//>> SET_[QME_QHB_HEARTBEAT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHB_HEARTBEAT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.setBit<QME_QHB_HEARTBEAT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QHB_HEARTBEAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHB_HEARTBEAT_ENABLE]

//>> CLEAR_[QME_QHB_HEARTBEAT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QHB_HEARTBEAT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.clearBit<QME_QHB_HEARTBEAT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QHB_HEARTBEAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QHB_HEARTBEAT_ENABLE]

//>> GET_[QME_QHB_HEARTBEAT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_QHB_HEARTBEAT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return i_data.extractToRight<QME_QHB_HEARTBEAT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QHB_HEARTBEAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHB_HEARTBEAT_ENABLE]

//>> GET_[QME_QHB_HEARTBEAT_ENABLE]
static inline bool GET_QME_QHB_HEARTBEAT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return i_data.getBit<QME_QHB_HEARTBEAT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QHB_HEARTBEAT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHB_HEARTBEAT_ENABLE]

//>> SET_[QME_QHB_SPARE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHB_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.insertFromRight<QME_QHB_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QHB_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHB_SPARE]

//>> SET_[QME_QHB_SPARE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHB_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.insertFromRight<QME_QHB_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QHB_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHB_SPARE]

//>> SET_[QME_QHB_SPARE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHB_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.setBit<QME_QHB_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QHB_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHB_SPARE]

//>> CLEAR_[QME_QHB_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QHB_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return o_data.clearBit<QME_QHB_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QHB_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QHB_SPARE]

//>> GET_[QME_QHB_SPARE]
static inline fapi2::buffer<uint64_t>& GET_QME_QHB_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return i_data.extractToRight<QME_QHB_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QHB_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHB_SPARE]

//>> GET_[QME_QHB_SPARE]
static inline bool GET_QME_QHB_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHB));
#endif
    return i_data.getBit<QME_QHB_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QHB_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHB_SPARE]

//>> PREP_[QME_RCSCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RCSCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCSCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RCSCR]

//>> GET_[QME_RCSCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RCSCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCSCR;
#endif
    return fapi2::getScom(i_target, QME_RCSCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RCSCR]

//>> PUT_[QME_RCSCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RCSCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_RCSCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RCSCR]

//>> PREP_[QME_RCSCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RCSCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCSCR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RCSCR_WO_CLEAR]

//>> GET_[QME_RCSCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RCSCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCSCR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, QME_RCSCR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RCSCR_WO_CLEAR]

//>> PUT_[QME_RCSCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RCSCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_RCSCR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RCSCR_WO_CLEAR]

//>> PREP_[QME_RCSCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RCSCR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCSCR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RCSCR_WO_OR]

//>> GET_[QME_RCSCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RCSCR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCSCR_WO_OR;
#endif
    return fapi2::getScom(i_target, QME_RCSCR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RCSCR_WO_OR]

//>> PUT_[QME_RCSCR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RCSCR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_RCSCR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RCSCR_WO_OR]


//>> SET_[QME_RCSCR_OFF_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_OFF_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_OFF_REQ,
           QME_RCSCR_OFF_REQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCSCR_OFF_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_OFF_REQ]

//>> SET_[QME_RCSCR_OFF_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_OFF_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_OFF_REQ,
           QME_RCSCR_OFF_REQ_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCSCR_OFF_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_OFF_REQ]

//>> GET_[QME_RCSCR_OFF_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_RCSCR_OFF_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCSCR_OFF_REQ,
           QME_RCSCR_OFF_REQ_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCSCR_OFF_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCSCR_OFF_REQ]

//>> SET_[QME_RCSCR_CHANGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_CHANGE_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_CHANGE_DONE,
           QME_RCSCR_CHANGE_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCSCR_CHANGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_CHANGE_DONE]

//>> SET_[QME_RCSCR_CHANGE_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_CHANGE_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_CHANGE_DONE,
           QME_RCSCR_CHANGE_DONE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCSCR_CHANGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_CHANGE_DONE]

//>> GET_[QME_RCSCR_CHANGE_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_RCSCR_CHANGE_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCSCR_CHANGE_DONE,
           QME_RCSCR_CHANGE_DONE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCSCR_CHANGE_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCSCR_CHANGE_DONE]

//>> SET_[QME_RCSCR_CHANGE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_CHANGE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_CHANGE_ACTIVE,
           QME_RCSCR_CHANGE_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCSCR_CHANGE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_CHANGE_ACTIVE]

//>> SET_[QME_RCSCR_CHANGE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_CHANGE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_CHANGE_ACTIVE,
           QME_RCSCR_CHANGE_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCSCR_CHANGE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_CHANGE_ACTIVE]

//>> GET_[QME_RCSCR_CHANGE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_RCSCR_CHANGE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCSCR_CHANGE_ACTIVE,
           QME_RCSCR_CHANGE_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCSCR_CHANGE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCSCR_CHANGE_ACTIVE]

//>> SET_[QME_RCSCR_PARTIAL_GOOD]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_PARTIAL_GOOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_PARTIAL_GOOD,
           QME_RCSCR_PARTIAL_GOOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCSCR_PARTIAL_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_PARTIAL_GOOD]

//>> SET_[QME_RCSCR_PARTIAL_GOOD]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_PARTIAL_GOOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_PARTIAL_GOOD,
           QME_RCSCR_PARTIAL_GOOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCSCR_PARTIAL_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_PARTIAL_GOOD]

//>> GET_[QME_RCSCR_PARTIAL_GOOD]
static inline fapi2::buffer<uint64_t>& GET_QME_RCSCR_PARTIAL_GOOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCSCR_PARTIAL_GOOD,
           QME_RCSCR_PARTIAL_GOOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCSCR_PARTIAL_GOOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCSCR_PARTIAL_GOOD]

//>> SET_[QME_RCSCR_CHANGE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_CHANGE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_CHANGE_ERROR,
           QME_RCSCR_CHANGE_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCSCR_CHANGE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_CHANGE_ERROR]

//>> SET_[QME_RCSCR_CHANGE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_CHANGE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_CHANGE_ERROR,
           QME_RCSCR_CHANGE_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCSCR_CHANGE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_CHANGE_ERROR]

//>> GET_[QME_RCSCR_CHANGE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_QME_RCSCR_CHANGE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCSCR_CHANGE_ERROR,
           QME_RCSCR_CHANGE_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCSCR_CHANGE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCSCR_CHANGE_ERROR]

//>> SET_[QME_RCSCR_0_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_0_TARGET_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_0_TARGET_INDEX,
           QME_RCSCR_0_TARGET_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCSCR_0_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_0_TARGET_INDEX]

//>> SET_[QME_RCSCR_0_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_0_TARGET_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_0_TARGET_INDEX,
           QME_RCSCR_0_TARGET_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCSCR_0_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_0_TARGET_INDEX]

//>> GET_[QME_RCSCR_0_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_RCSCR_0_TARGET_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCSCR_0_TARGET_INDEX,
           QME_RCSCR_0_TARGET_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCSCR_0_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCSCR_0_TARGET_INDEX]

//>> SET_[QME_RCSCR_1_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_1_TARGET_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_1_TARGET_INDEX,
           QME_RCSCR_1_TARGET_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCSCR_1_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_1_TARGET_INDEX]

//>> SET_[QME_RCSCR_1_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_1_TARGET_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_1_TARGET_INDEX,
           QME_RCSCR_1_TARGET_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCSCR_1_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_1_TARGET_INDEX]

//>> GET_[QME_RCSCR_1_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_RCSCR_1_TARGET_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCSCR_1_TARGET_INDEX,
           QME_RCSCR_1_TARGET_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCSCR_1_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCSCR_1_TARGET_INDEX]

//>> SET_[QME_RCSCR_2_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_2_TARGET_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_2_TARGET_INDEX,
           QME_RCSCR_2_TARGET_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCSCR_2_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_2_TARGET_INDEX]

//>> SET_[QME_RCSCR_2_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_2_TARGET_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_2_TARGET_INDEX,
           QME_RCSCR_2_TARGET_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCSCR_2_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_2_TARGET_INDEX]

//>> GET_[QME_RCSCR_2_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_RCSCR_2_TARGET_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCSCR_2_TARGET_INDEX,
           QME_RCSCR_2_TARGET_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCSCR_2_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCSCR_2_TARGET_INDEX]

//>> SET_[QME_RCSCR_3_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_3_TARGET_INDEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_3_TARGET_INDEX,
           QME_RCSCR_3_TARGET_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCSCR_3_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_3_TARGET_INDEX]

//>> SET_[QME_RCSCR_3_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& SET_QME_RCSCR_3_TARGET_INDEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return o_data.insertFromRight<QME_RCSCR_3_TARGET_INDEX,
           QME_RCSCR_3_TARGET_INDEX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCSCR_3_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCSCR_3_TARGET_INDEX]

//>> GET_[QME_RCSCR_3_TARGET_INDEX]
static inline fapi2::buffer<uint64_t>& GET_QME_RCSCR_3_TARGET_INDEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCSCR, QME_RCSCR_WO_CLEAR, QME_RCSCR_WO_OR));
#endif
    return i_data.extractToRight<QME_RCSCR_3_TARGET_INDEX,
           QME_RCSCR_3_TARGET_INDEX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCSCR_3_TARGET_INDEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCSCR_3_TARGET_INDEX]

//>> PREP_[XSTOP1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP1]

//>> GET_[XSTOP1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP1(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP1;
#endif
    return fapi2::getScom(i_target, XSTOP1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP1]

//>> PUT_[XSTOP1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return fapi2::putScom(i_target, XSTOP1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP1]


//>> SET_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_ENABLE]

//>> SET_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_ENABLE]

//>> SET_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_ENABLE]

//>> CLEAR_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_ENABLE]

//>> GET_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_ENABLE]

//>> GET_[XSTOP1_ENABLE]
static inline bool GET_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_ENABLE]

//>> SET_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_SNOPA]

//>> SET_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_SNOPA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_SNOPA]

//>> SET_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_SNOPA]

//>> CLEAR_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_WAIT_SNOPA]

//>> GET_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_WAIT_SNOPA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_SNOPA]

//>> GET_[XSTOP1_WAIT_SNOPA]
static inline bool GET_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_SNOPA]

//>> SET_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_TRIGGER_OPCG_GO]

//>> SET_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_TRIGGER_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_TRIGGER_OPCG_GO]

//>> SET_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_TRIGGER_OPCG_GO]

//>> CLEAR_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_TRIGGER_OPCG_GO]

//>> GET_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_TRIGGER_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_TRIGGER_OPCG_GO]

//>> GET_[XSTOP1_TRIGGER_OPCG_GO]
static inline bool GET_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_TRIGGER_OPCG_GO]

//>> SET_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_ALWAYS]

//>> SET_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_ALWAYS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_ALWAYS]

//>> SET_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_ALWAYS]

//>> CLEAR_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_WAIT_ALWAYS]

//>> GET_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_WAIT_ALWAYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_ALWAYS]

//>> GET_[XSTOP1_WAIT_ALWAYS]
static inline bool GET_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_ALWAYS]

//>> SET_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_PERV]

//>> SET_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_PERV]

//>> SET_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_PERV]

//>> CLEAR_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_PERV]

//>> GET_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_PERV]

//>> GET_[XSTOP1_REGION_PERV]
static inline bool GET_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_PERV]

//>> SET_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT1]

//>> SET_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT1]

//>> SET_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT1]

//>> CLEAR_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT1]

//>> GET_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT1]

//>> GET_[XSTOP1_REGION_UNIT1]
static inline bool GET_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT1]

//>> SET_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT2]

//>> SET_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT2]

//>> SET_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT2]

//>> CLEAR_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT2]

//>> GET_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT2]

//>> GET_[XSTOP1_REGION_UNIT2]
static inline bool GET_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT2]

//>> SET_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT3]

//>> SET_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT3]

//>> SET_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT3]

//>> CLEAR_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT3]

//>> GET_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT3]

//>> GET_[XSTOP1_REGION_UNIT3]
static inline bool GET_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT3]

//>> SET_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT4]

//>> SET_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT4]

//>> SET_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT4]

//>> CLEAR_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT4]

//>> GET_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT4]

//>> GET_[XSTOP1_REGION_UNIT4]
static inline bool GET_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT4]

//>> SET_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT5]

//>> SET_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT5]

//>> SET_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT5]

//>> CLEAR_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT5]

//>> GET_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT5]

//>> GET_[XSTOP1_REGION_UNIT5]
static inline bool GET_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT5]

//>> SET_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT6]

//>> SET_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT6]

//>> SET_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT6]

//>> CLEAR_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT6]

//>> GET_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT6]

//>> GET_[XSTOP1_REGION_UNIT6]
static inline bool GET_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT6]

//>> SET_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT7]

//>> SET_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT7]

//>> SET_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT7]

//>> CLEAR_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT7]

//>> GET_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT7]

//>> GET_[XSTOP1_REGION_UNIT7]
static inline bool GET_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT7]

//>> SET_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT8]

//>> SET_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT8]

//>> SET_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT8]

//>> CLEAR_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT8]

//>> GET_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT8]

//>> GET_[XSTOP1_REGION_UNIT8]
static inline bool GET_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT8]

//>> SET_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT9]

//>> SET_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT9]

//>> SET_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT9]

//>> CLEAR_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT9]

//>> GET_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT9]

//>> GET_[XSTOP1_REGION_UNIT9]
static inline bool GET_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT9]

//>> SET_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT10]

//>> SET_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT10]

//>> SET_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT10]

//>> CLEAR_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT10]

//>> GET_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT10]

//>> GET_[XSTOP1_REGION_UNIT10]
static inline bool GET_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT10]

//>> SET_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT11]

//>> SET_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT11]

//>> SET_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT11]

//>> CLEAR_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT11]

//>> GET_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT11]

//>> GET_[XSTOP1_REGION_UNIT11]
static inline bool GET_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT11]

//>> SET_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT12]

//>> SET_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT12]

//>> SET_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT12]

//>> CLEAR_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT12]

//>> GET_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT12]

//>> GET_[XSTOP1_REGION_UNIT12]
static inline bool GET_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT12]

//>> SET_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT13]

//>> SET_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT13]

//>> SET_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT13]

//>> CLEAR_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT13]

//>> GET_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT13]

//>> GET_[XSTOP1_REGION_UNIT13]
static inline bool GET_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT13]

//>> SET_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT14]

//>> SET_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT14]

//>> SET_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT14]

//>> CLEAR_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT14]

//>> GET_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT14]

//>> GET_[XSTOP1_REGION_UNIT14]
static inline bool GET_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT14]

//>> SET_[XSTOP1_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_CYCLES,
           XSTOP1_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access XSTOP1_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_CYCLES]

//>> SET_[XSTOP1_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_CYCLES,
           XSTOP1_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access XSTOP1_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_CYCLES]

//>> GET_[XSTOP1_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_WAIT_CYCLES,
           XSTOP1_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access XSTOP1_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_CYCLES]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
