/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00020.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __PERV_REG00020_H_
#define __PERV_REG00020_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[CLOCK_STAT_SL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLOCK_STAT_SL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CLOCK_STAT_SL]

//>> GET_[CLOCK_STAT_SL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CLOCK_STAT_SL;
#endif
    return fapi2::getScom(i_target, CLOCK_STAT_SL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CLOCK_STAT_SL]

//>> PUT_[CLOCK_STAT_SL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CLOCK_STAT_SL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return fapi2::putScom(i_target, CLOCK_STAT_SL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CLOCK_STAT_SL]


//>> SET_[CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_PERV_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_PERV_SL]

//>> SET_[CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_PERV_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_PERV_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_PERV_SL]

//>> SET_[CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_PERV_SL]

//>> CLEAR_[CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_PERV_SL]

//>> GET_[CLOCK_STAT_SL_PERV_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_PERV_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_PERV_SL]

//>> GET_[CLOCK_STAT_SL_PERV_SL]
static inline bool GET_CLOCK_STAT_SL_PERV_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_PERV_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_PERV_SL]

//>> SET_[CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT1_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT1_SL]

//>> SET_[CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT1_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT1_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT1_SL]

//>> SET_[CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT1_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT1_SL]

//>> GET_[CLOCK_STAT_SL_UNIT1_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT1_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT1_SL]

//>> GET_[CLOCK_STAT_SL_UNIT1_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT1_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT1_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT1_SL]

//>> SET_[CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT2_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT2_SL]

//>> SET_[CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT2_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT2_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT2_SL]

//>> SET_[CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT2_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT2_SL]

//>> GET_[CLOCK_STAT_SL_UNIT2_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT2_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT2_SL]

//>> GET_[CLOCK_STAT_SL_UNIT2_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT2_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT2_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT2_SL]

//>> SET_[CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT3_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT3_SL]

//>> SET_[CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT3_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT3_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT3_SL]

//>> SET_[CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT3_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT3_SL]

//>> GET_[CLOCK_STAT_SL_UNIT3_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT3_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT3_SL]

//>> GET_[CLOCK_STAT_SL_UNIT3_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT3_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT3_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT3_SL]

//>> SET_[CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT4_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT4_SL]

//>> SET_[CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT4_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT4_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT4_SL]

//>> SET_[CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT4_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT4_SL]

//>> GET_[CLOCK_STAT_SL_UNIT4_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT4_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT4_SL]

//>> GET_[CLOCK_STAT_SL_UNIT4_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT4_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT4_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT4_SL]

//>> SET_[CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT5_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT5_SL]

//>> SET_[CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT5_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT5_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT5_SL]

//>> SET_[CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT5_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT5_SL]

//>> GET_[CLOCK_STAT_SL_UNIT5_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT5_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT5_SL]

//>> GET_[CLOCK_STAT_SL_UNIT5_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT5_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT5_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT5_SL]

//>> SET_[CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT6_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT6_SL]

//>> SET_[CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT6_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT6_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT6_SL]

//>> SET_[CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT6_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT6_SL]

//>> GET_[CLOCK_STAT_SL_UNIT6_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT6_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT6_SL]

//>> GET_[CLOCK_STAT_SL_UNIT6_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT6_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT6_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT6_SL]

//>> SET_[CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT7_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT7_SL]

//>> SET_[CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT7_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT7_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT7_SL]

//>> SET_[CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT7_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT7_SL]

//>> GET_[CLOCK_STAT_SL_UNIT7_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT7_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT7_SL]

//>> GET_[CLOCK_STAT_SL_UNIT7_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT7_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT7_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT7_SL]

//>> SET_[CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT8_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT8_SL]

//>> SET_[CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT8_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT8_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT8_SL]

//>> SET_[CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT8_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT8_SL]

//>> GET_[CLOCK_STAT_SL_UNIT8_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT8_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT8_SL]

//>> GET_[CLOCK_STAT_SL_UNIT8_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT8_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT8_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT8_SL]

//>> SET_[CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT9_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT9_SL]

//>> SET_[CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT9_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT9_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT9_SL]

//>> SET_[CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT9_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT9_SL]

//>> GET_[CLOCK_STAT_SL_UNIT9_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT9_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT9_SL]

//>> GET_[CLOCK_STAT_SL_UNIT9_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT9_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT9_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT9_SL]

//>> SET_[CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT10_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT10_SL]

//>> SET_[CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT10_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT10_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT10_SL]

//>> SET_[CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT10_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT10_SL]

//>> GET_[CLOCK_STAT_SL_UNIT10_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT10_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT10_SL]

//>> GET_[CLOCK_STAT_SL_UNIT10_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT10_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT10_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT10_SL]

//>> SET_[CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT11_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT11_SL]

//>> SET_[CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT11_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT11_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT11_SL]

//>> SET_[CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT11_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT11_SL]

//>> GET_[CLOCK_STAT_SL_UNIT11_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT11_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT11_SL]

//>> GET_[CLOCK_STAT_SL_UNIT11_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT11_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT11_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT11_SL]

//>> SET_[CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT12_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT12_SL]

//>> SET_[CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT12_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT12_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT12_SL]

//>> SET_[CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT12_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT12_SL]

//>> GET_[CLOCK_STAT_SL_UNIT12_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT12_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT12_SL]

//>> GET_[CLOCK_STAT_SL_UNIT12_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT12_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT12_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT12_SL]

//>> SET_[CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT13_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT13_SL]

//>> SET_[CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT13_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT13_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT13_SL]

//>> SET_[CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT13_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT13_SL]

//>> GET_[CLOCK_STAT_SL_UNIT13_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT13_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT13_SL]

//>> GET_[CLOCK_STAT_SL_UNIT13_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT13_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT13_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT13_SL]

//>> SET_[CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT14_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT14_SL]

//>> SET_[CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT14_SL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.insertFromRight<CLOCK_STAT_SL_UNIT14_SL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT14_SL]

//>> SET_[CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& SET_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.setBit<CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CLOCK_STAT_SL_UNIT14_SL]

//>> CLEAR_[CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& CLEAR_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return o_data.clearBit<CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CLOCK_STAT_SL_UNIT14_SL]

//>> GET_[CLOCK_STAT_SL_UNIT14_SL]
static inline fapi2::buffer<uint64_t>& GET_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.extractToRight<CLOCK_STAT_SL_UNIT14_SL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT14_SL]

//>> GET_[CLOCK_STAT_SL_UNIT14_SL]
static inline bool GET_CLOCK_STAT_SL_UNIT14_SL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CLOCK_STAT_SL));
#endif
    return i_data.getBit<CLOCK_STAT_SL_UNIT14_SL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CLOCK_STAT_SL_UNIT14_SL]

//>> PREP_[CPLT_CTRL3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL3_RW]

//>> GET_[CPLT_CTRL3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL3_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL3_RW]

//>> PUT_[CPLT_CTRL3_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL3_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL3_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL3_RW]

//>> PREP_[CPLT_CTRL3_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL3_WO_CLEAR]

//>> GET_[CPLT_CTRL3_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL3_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL3_WO_CLEAR]

//>> PUT_[CPLT_CTRL3_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL3_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL3_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL3_WO_CLEAR]

//>> PREP_[CPLT_CTRL3_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL3_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL3_WO_OR]

//>> GET_[CPLT_CTRL3_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL3_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL3_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL3_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL3_WO_OR]

//>> PUT_[CPLT_CTRL3_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL3_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL3_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL3_WO_OR]


//>> SET_[CPLT_CTRL3_0_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_0_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_0_PSCOM_EN]

//>> SET_[CPLT_CTRL3_0_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_0_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_0_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_0_PSCOM_EN]

//>> SET_[CPLT_CTRL3_0_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_0_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_0_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_0_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_0_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_0_PSCOM_EN]

//>> GET_[CPLT_CTRL3_0_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_0_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_0_PSCOM_EN]

//>> GET_[CPLT_CTRL3_0_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_0_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_0_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_0_PSCOM_EN]

//>> SET_[CPLT_CTRL3_1_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_1_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_1_PSCOM_EN]

//>> SET_[CPLT_CTRL3_1_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_1_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_1_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_1_PSCOM_EN]

//>> SET_[CPLT_CTRL3_1_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_1_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_1_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_1_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_1_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_1_PSCOM_EN]

//>> GET_[CPLT_CTRL3_1_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_1_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_1_PSCOM_EN]

//>> GET_[CPLT_CTRL3_1_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_1_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_1_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_1_PSCOM_EN]

//>> SET_[CPLT_CTRL3_2_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_2_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_2_PSCOM_EN]

//>> SET_[CPLT_CTRL3_2_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_2_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_2_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_2_PSCOM_EN]

//>> SET_[CPLT_CTRL3_2_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_2_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_2_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_2_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_2_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_2_PSCOM_EN]

//>> GET_[CPLT_CTRL3_2_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_2_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_2_PSCOM_EN]

//>> GET_[CPLT_CTRL3_2_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_2_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_2_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_2_PSCOM_EN]

//>> SET_[CPLT_CTRL3_3_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_3_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_3_PSCOM_EN]

//>> SET_[CPLT_CTRL3_3_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_3_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_3_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_3_PSCOM_EN]

//>> SET_[CPLT_CTRL3_3_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_3_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_3_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_3_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_3_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_3_PSCOM_EN]

//>> GET_[CPLT_CTRL3_3_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_3_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_3_PSCOM_EN]

//>> GET_[CPLT_CTRL3_3_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_3_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_3_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_3_PSCOM_EN]

//>> SET_[CPLT_CTRL3_4_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_4_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_4_PSCOM_EN]

//>> SET_[CPLT_CTRL3_4_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_4_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_4_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_4_PSCOM_EN]

//>> SET_[CPLT_CTRL3_4_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_4_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_4_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_4_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_4_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_4_PSCOM_EN]

//>> GET_[CPLT_CTRL3_4_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_4_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_4_PSCOM_EN]

//>> GET_[CPLT_CTRL3_4_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_4_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_4_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_4_PSCOM_EN]

//>> SET_[CPLT_CTRL3_5_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_5_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_5_PSCOM_EN]

//>> SET_[CPLT_CTRL3_5_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_5_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_5_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_5_PSCOM_EN]

//>> SET_[CPLT_CTRL3_5_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_5_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_5_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_5_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_5_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_5_PSCOM_EN]

//>> GET_[CPLT_CTRL3_5_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_5_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_5_PSCOM_EN]

//>> GET_[CPLT_CTRL3_5_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_5_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_5_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_5_PSCOM_EN]

//>> SET_[CPLT_CTRL3_6_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_6_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_6_PSCOM_EN]

//>> SET_[CPLT_CTRL3_6_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_6_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_6_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_6_PSCOM_EN]

//>> SET_[CPLT_CTRL3_6_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_6_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_6_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_6_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_6_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_6_PSCOM_EN]

//>> GET_[CPLT_CTRL3_6_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_6_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_6_PSCOM_EN]

//>> GET_[CPLT_CTRL3_6_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_6_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_6_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_6_PSCOM_EN]

//>> SET_[CPLT_CTRL3_7_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_7_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_7_PSCOM_EN]

//>> SET_[CPLT_CTRL3_7_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_7_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_7_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_7_PSCOM_EN]

//>> SET_[CPLT_CTRL3_7_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_7_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_7_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_7_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_7_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_7_PSCOM_EN]

//>> GET_[CPLT_CTRL3_7_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_7_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_7_PSCOM_EN]

//>> GET_[CPLT_CTRL3_7_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_7_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_7_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_7_PSCOM_EN]

//>> SET_[CPLT_CTRL3_8_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_8_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_8_PSCOM_EN]

//>> SET_[CPLT_CTRL3_8_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_8_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_8_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_8_PSCOM_EN]

//>> SET_[CPLT_CTRL3_8_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_8_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_8_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_8_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_8_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_8_PSCOM_EN]

//>> GET_[CPLT_CTRL3_8_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_8_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_8_PSCOM_EN]

//>> GET_[CPLT_CTRL3_8_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_8_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_8_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_8_PSCOM_EN]

//>> SET_[CPLT_CTRL3_9_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_9_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_9_PSCOM_EN]

//>> SET_[CPLT_CTRL3_9_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_9_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_9_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_9_PSCOM_EN]

//>> SET_[CPLT_CTRL3_9_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_9_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_9_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_9_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_9_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_9_PSCOM_EN]

//>> GET_[CPLT_CTRL3_9_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_9_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_9_PSCOM_EN]

//>> GET_[CPLT_CTRL3_9_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_9_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_9_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_9_PSCOM_EN]

//>> SET_[CPLT_CTRL3_10_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_10_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_10_PSCOM_EN]

//>> SET_[CPLT_CTRL3_10_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_10_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_10_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_10_PSCOM_EN]

//>> SET_[CPLT_CTRL3_10_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_10_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_10_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_10_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_10_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_10_PSCOM_EN]

//>> GET_[CPLT_CTRL3_10_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_10_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_10_PSCOM_EN]

//>> GET_[CPLT_CTRL3_10_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_10_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_10_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_10_PSCOM_EN]

//>> SET_[CPLT_CTRL3_11_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_11_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_11_PSCOM_EN]

//>> SET_[CPLT_CTRL3_11_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_11_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_11_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_11_PSCOM_EN]

//>> SET_[CPLT_CTRL3_11_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_11_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_11_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_11_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_11_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_11_PSCOM_EN]

//>> GET_[CPLT_CTRL3_11_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_11_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_11_PSCOM_EN]

//>> GET_[CPLT_CTRL3_11_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_11_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_11_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_11_PSCOM_EN]

//>> SET_[CPLT_CTRL3_12_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_12_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_12_PSCOM_EN]

//>> SET_[CPLT_CTRL3_12_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_12_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_12_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_12_PSCOM_EN]

//>> SET_[CPLT_CTRL3_12_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_12_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_12_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_12_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_12_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_12_PSCOM_EN]

//>> GET_[CPLT_CTRL3_12_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_12_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_12_PSCOM_EN]

//>> GET_[CPLT_CTRL3_12_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_12_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_12_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_12_PSCOM_EN]

//>> SET_[CPLT_CTRL3_13_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_13_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_13_PSCOM_EN]

//>> SET_[CPLT_CTRL3_13_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_13_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_13_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_13_PSCOM_EN]

//>> SET_[CPLT_CTRL3_13_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_13_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_13_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_13_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_13_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_13_PSCOM_EN]

//>> GET_[CPLT_CTRL3_13_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_13_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_13_PSCOM_EN]

//>> GET_[CPLT_CTRL3_13_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_13_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_13_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_13_PSCOM_EN]

//>> SET_[CPLT_CTRL3_14_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_14_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_14_PSCOM_EN]

//>> SET_[CPLT_CTRL3_14_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_14_PSCOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL3_14_PSCOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_14_PSCOM_EN]

//>> SET_[CPLT_CTRL3_14_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL3_14_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL3_14_PSCOM_EN]

//>> CLEAR_[CPLT_CTRL3_14_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL3_14_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL3_14_PSCOM_EN]

//>> GET_[CPLT_CTRL3_14_PSCOM_EN]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL3_14_PSCOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_14_PSCOM_EN]

//>> GET_[CPLT_CTRL3_14_PSCOM_EN]
static inline bool GET_CPLT_CTRL3_14_PSCOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL3_RW, CPLT_CTRL3_WO_CLEAR, CPLT_CTRL3_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL3_14_PSCOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_14_PSCOM_EN]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR]

//>> PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR]


//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC,
           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC,
           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC,
           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED]

//>> SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED]

//>> GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI, FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED,
           FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]
static inline bool GET_FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI, FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC]

//>> PREP_[FSXCOMP_FSXLOG_SB_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SB_CS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_CS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SB_CS]

//>> GET_[FSXCOMP_FSXLOG_SB_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SB_CS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_CS;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SB_CS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS]

//>> PUT_[FSXCOMP_FSXLOG_SB_CS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SB_CS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SB_CS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SB_CS]

//>> PREP_[FSXCOMP_FSXLOG_SB_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SB_CS_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_CS_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SB_CS_FSI]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SB_CS_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_CS_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SB_CS_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SB_CS_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SB_CS_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SB_CS_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SB_CS_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SB_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_CS_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SB_CS_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SB_CS_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SB_CS_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SB_CS_FSI_BYTE]


//>> SET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]

//>> CLEAR_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]
static inline bool GET_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]

//>> CLEAR_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]
static inline bool GET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]

//>> CLEAR_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]
static inline bool GET_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]

//>> CLEAR_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]
static inline bool GET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]

//>> CLEAR_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]
static inline bool GET_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]

//>> CLEAR_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]
static inline bool GET_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]

//>> CLEAR_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]
static inline bool GET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]

//>> SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.setBit<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]

//>> CLEAR_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]
static inline fapi2::buffer<uint64_t>& CLEAR_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return o_data.clearBit<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]

//>> GET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]
static inline bool GET_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SB_CS, FSXCOMP_FSXLOG_SB_CS_FSI, FSXCOMP_FSXLOG_SB_CS_FSI_BYTE));
#endif
    return i_data.getBit<FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW]

//>> PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW]


//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10]

//>> SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10]

//>> GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI, FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE,
                           FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10,
           FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10]

//>> PREP_[REC_ERR_MST14_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_MST14_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST14_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REC_ERR_MST14_REG0]

//>> GET_[REC_ERR_MST14_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_MST14_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST14_REG0;
#endif
    return fapi2::getScom(i_target, REC_ERR_MST14_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REC_ERR_MST14_REG0]

//>> PUT_[REC_ERR_MST14_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_MST14_REG0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return fapi2::putScom(i_target, REC_ERR_MST14_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REC_ERR_MST14_REG0]


//>> SET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.setBit<REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.getBit<REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG0));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE,
           REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE]

//>> PREP_[TOD_ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_ERROR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_ERROR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_ERROR_REG]

//>> GET_[TOD_ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_ERROR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_ERROR_REG;
#endif
    return fapi2::getScom(i_target, TOD_ERROR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_ERROR_REG]

//>> PUT_[TOD_ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_ERROR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return fapi2::putScom(i_target, TOD_ERROR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_ERROR_REG]


//>> SET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_M_PATH_0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_0_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_M_PATH_0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_M_PATH_0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_M_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_M_PATH_0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_M_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_M_PATH_0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_M_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_M_PATH_0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_M_PATH_0_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_M_PATH_1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_1_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_M_PATH_1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_M_PATH_1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_M_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_M_PATH_1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_M_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_M_PATH_1_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_M_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_M_PATH_1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_M_PATH_1_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_S_PATH_0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_0_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_S_PATH_0_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_S_PATH_0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_S_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_S_PATH_0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_S_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_S_PATH_0_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_S_PATH_0_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_S_PATH_0_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_S_PATH_0_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]

//>> CLEAR_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]
static inline bool GET_TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]

//>> CLEAR_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]
static inline bool GET_TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]

//>> CLEAR_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]
static inline bool GET_TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]

//>> CLEAR_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]
static inline bool GET_TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_PSS_HAM]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PSS_HAM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PSS_HAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_PSS_HAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PSS_HAM]

//>> SET_[TOD_ERROR_REG_PSS_HAM]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PSS_HAM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PSS_HAM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_PSS_HAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PSS_HAM]

//>> SET_[TOD_ERROR_REG_PSS_HAM]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PSS_HAM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_PSS_HAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_PSS_HAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PSS_HAM]

//>> CLEAR_[TOD_ERROR_REG_PSS_HAM]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_PSS_HAM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_PSS_HAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_PSS_HAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_PSS_HAM]

//>> GET_[TOD_ERROR_REG_PSS_HAM]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_PSS_HAM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_PSS_HAM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_PSS_HAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PSS_HAM]

//>> GET_[TOD_ERROR_REG_PSS_HAM]
static inline bool GET_TOD_ERROR_REG_PSS_HAM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_PSS_HAM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_PSS_HAM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PSS_HAM]

//>> SET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_S_PATH_1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_1_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_S_PATH_1_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_S_PATH_1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_S_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_S_PATH_1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_S_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_S_PATH_1_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_S_PATH_1_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_S_PATH_1_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_S_PATH_1_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]

//>> CLEAR_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]
static inline bool GET_TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]

//>> CLEAR_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]
static inline bool GET_TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]

//>> SET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]

//>> SET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]

//>> CLEAR_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]

//>> GET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]

//>> GET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]
static inline bool GET_TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW]

//>> SET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_0]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_0]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_0]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_0]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_0]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_RX_TTYPE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_0]

//>> CLEAR_[TOD_ERROR_REG_RX_TTYPE_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_RX_TTYPE_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_RX_TTYPE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_RX_TTYPE_0]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_0]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_RX_TTYPE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_RX_TTYPE_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_0]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_0]
static inline bool GET_TOD_ERROR_REG_RX_TTYPE_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_RX_TTYPE_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_0]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_1]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_1]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_1]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_1]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_1]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_RX_TTYPE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_1]

//>> CLEAR_[TOD_ERROR_REG_RX_TTYPE_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_RX_TTYPE_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_RX_TTYPE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_RX_TTYPE_1]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_1]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_RX_TTYPE_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_RX_TTYPE_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_1]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_1]
static inline bool GET_TOD_ERROR_REG_RX_TTYPE_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_RX_TTYPE_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_1]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_2]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_2]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_2]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_2]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_2]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_RX_TTYPE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_2]

//>> CLEAR_[TOD_ERROR_REG_RX_TTYPE_2]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_RX_TTYPE_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_RX_TTYPE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_RX_TTYPE_2]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_2]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_RX_TTYPE_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_RX_TTYPE_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_2]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_2]
static inline bool GET_TOD_ERROR_REG_RX_TTYPE_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_RX_TTYPE_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_2]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_3]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_3]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_3]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_3]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_3]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_RX_TTYPE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_3]

//>> CLEAR_[TOD_ERROR_REG_RX_TTYPE_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_RX_TTYPE_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_RX_TTYPE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_RX_TTYPE_3]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_3]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_RX_TTYPE_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_RX_TTYPE_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_3]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_3]
static inline bool GET_TOD_ERROR_REG_RX_TTYPE_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_RX_TTYPE_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_3]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_4]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_4]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_4]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_4]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_4]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_RX_TTYPE_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_4]

//>> CLEAR_[TOD_ERROR_REG_RX_TTYPE_4]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_RX_TTYPE_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_RX_TTYPE_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_RX_TTYPE_4]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_4]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_RX_TTYPE_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_RX_TTYPE_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_4]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_4]
static inline bool GET_TOD_ERROR_REG_RX_TTYPE_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_RX_TTYPE_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_4]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_5]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_5]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_5]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_5]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_5]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_RX_TTYPE_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_5]

//>> CLEAR_[TOD_ERROR_REG_RX_TTYPE_5]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_RX_TTYPE_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_RX_TTYPE_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_RX_TTYPE_5]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_5]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_RX_TTYPE_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_RX_TTYPE_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_5]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_5]
static inline bool GET_TOD_ERROR_REG_RX_TTYPE_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_RX_TTYPE_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_5]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]

//>> CLEAR_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]
static inline bool GET_TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]

//>> CLEAR_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]
static inline bool GET_TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]

//>> CLEAR_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]
static inline bool GET_TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR,
           TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR,
           TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR,
           TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]

//>> CLEAR_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]
static inline bool GET_TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]

//>> CLEAR_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]

//>> GET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]
static inline bool GET_TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]

//>> CLEAR_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]
static inline bool GET_TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]

//>> SET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]

//>> CLEAR_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]

//>> GET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]
static inline bool GET_TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR]

//>> SET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]

//>> SET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]

//>> SET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]

//>> CLEAR_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]

//>> GET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]

//>> GET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]
static inline bool GET_TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_58]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_58]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_58]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_58]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_58]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_SPARE_ERROR_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_58]

//>> CLEAR_[TOD_ERROR_REG_SPARE_ERROR_58]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_SPARE_ERROR_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_SPARE_ERROR_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_SPARE_ERROR_58]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_58]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_SPARE_ERROR_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_SPARE_ERROR_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_58]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_58]
static inline bool GET_TOD_ERROR_REG_SPARE_ERROR_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_SPARE_ERROR_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_58]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_59]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_59]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_59]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_59]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_59]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_SPARE_ERROR_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_59]

//>> CLEAR_[TOD_ERROR_REG_SPARE_ERROR_59]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_SPARE_ERROR_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_SPARE_ERROR_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_SPARE_ERROR_59]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_59]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_SPARE_ERROR_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_SPARE_ERROR_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_59]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_59]
static inline bool GET_TOD_ERROR_REG_SPARE_ERROR_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_SPARE_ERROR_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_59]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_60]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_60]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_60]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_60]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_60]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_SPARE_ERROR_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_60]

//>> CLEAR_[TOD_ERROR_REG_SPARE_ERROR_60]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_SPARE_ERROR_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_SPARE_ERROR_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_SPARE_ERROR_60]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_60]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_SPARE_ERROR_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_SPARE_ERROR_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_60]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_60]
static inline bool GET_TOD_ERROR_REG_SPARE_ERROR_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_SPARE_ERROR_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_60]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_61]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_61]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_61]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_61]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_61]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_SPARE_ERROR_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_61]

//>> CLEAR_[TOD_ERROR_REG_SPARE_ERROR_61]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_SPARE_ERROR_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_SPARE_ERROR_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_SPARE_ERROR_61]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_61]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_SPARE_ERROR_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_SPARE_ERROR_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_61]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_61]
static inline bool GET_TOD_ERROR_REG_SPARE_ERROR_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_SPARE_ERROR_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_61]

//>> SET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_OSCSWITCH_INTERRUPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_OSCSWITCH_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_OSCSWITCH_INTERRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]

//>> SET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_OSCSWITCH_INTERRUPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_OSCSWITCH_INTERRUPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_OSCSWITCH_INTERRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]

//>> SET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_OSCSWITCH_INTERRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_OSCSWITCH_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_OSCSWITCH_INTERRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]

//>> CLEAR_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_OSCSWITCH_INTERRUPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_OSCSWITCH_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_OSCSWITCH_INTERRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]

//>> GET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_OSCSWITCH_INTERRUPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_OSCSWITCH_INTERRUPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_OSCSWITCH_INTERRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]

//>> GET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]
static inline bool GET_TOD_ERROR_REG_OSCSWITCH_INTERRUPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_OSCSWITCH_INTERRUPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_OSCSWITCH_INTERRUPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_OSCSWITCH_INTERRUPT]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_63]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_63]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_63]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.insertFromRight<TOD_ERROR_REG_SPARE_ERROR_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_63]

//>> SET_[TOD_ERROR_REG_SPARE_ERROR_63]
static inline fapi2::buffer<uint64_t>& SET_TOD_ERROR_REG_SPARE_ERROR_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.setBit<TOD_ERROR_REG_SPARE_ERROR_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_ERROR_REG_SPARE_ERROR_63]

//>> CLEAR_[TOD_ERROR_REG_SPARE_ERROR_63]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_ERROR_REG_SPARE_ERROR_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return o_data.clearBit<TOD_ERROR_REG_SPARE_ERROR_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_ERROR_REG_SPARE_ERROR_63]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_63]
static inline fapi2::buffer<uint64_t>& GET_TOD_ERROR_REG_SPARE_ERROR_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.extractToRight<TOD_ERROR_REG_SPARE_ERROR_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_63]

//>> GET_[TOD_ERROR_REG_SPARE_ERROR_63]
static inline bool GET_TOD_ERROR_REG_SPARE_ERROR_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_ERROR_REG));
#endif
    return i_data.getBit<TOD_ERROR_REG_SPARE_ERROR_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_ERROR_REG_SPARE_ERROR_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_ERROR_REG_SPARE_ERROR_63]


//>> PREP_[OTPC_M_I2CM_SLVID_CONFIG_REG_B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTPC_M_I2CM_SLVID_CONFIG_REG_B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = OTPC_M_I2CM_SLVID_CONFIG_REG_B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OTPC_M_I2CM_SLVID_CONFIG_REG_B]

//>> GET_[OTPC_M_I2CM_SLVID_CONFIG_REG_B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTPC_M_I2CM_SLVID_CONFIG_REG_B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    scomt::last_scom = OTPC_M_I2CM_SLVID_CONFIG_REG_B;
#endif
    return fapi2::getScom(i_target, OTPC_M_I2CM_SLVID_CONFIG_REG_B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OTPC_M_I2CM_SLVID_CONFIG_REG_B]

//>> PUT_[OTPC_M_I2CM_SLVID_CONFIG_REG_B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTPC_M_I2CM_SLVID_CONFIG_REG_B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return fapi2::putScom(i_target, OTPC_M_I2CM_SLVID_CONFIG_REG_B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OTPC_M_I2CM_SLVID_CONFIG_REG_B]


//>> SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B]
static inline fapi2::buffer<uint64_t>& SET_P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return o_data.insertFromRight<P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B,
           P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B]

//>> SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B]
static inline fapi2::buffer<uint64_t>& SET_P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return o_data.insertFromRight<P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B,
           P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B]

//>> GET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B]
static inline fapi2::buffer<uint64_t>& GET_P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return i_data.extractToRight<P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B,
           P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_PORT_PROTECTION_B]

//>> SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B]
static inline fapi2::buffer<uint64_t>& SET_P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return o_data.insertFromRight<P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B,
           P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B]

//>> SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B]
static inline fapi2::buffer<uint64_t>& SET_P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return o_data.insertFromRight<P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B,
           P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B]

//>> GET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B]
static inline fapi2::buffer<uint64_t>& GET_P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return i_data.extractToRight<P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B,
           P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_SLV_ID_B]

//>> SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B]
static inline fapi2::buffer<uint64_t>& SET_P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return o_data.insertFromRight<P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B,
           P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B]

//>> SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B]
static inline fapi2::buffer<uint64_t>& SET_P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return o_data.insertFromRight<P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B,
           P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B]

//>> GET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B]
static inline fapi2::buffer<uint64_t>& GET_P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(OTPC_M_I2CM_SLVID_CONFIG_REG_B));
#endif
    return i_data.extractToRight<P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B,
           P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_OTPC_M_I2CM_SLVID_CONFIG_REG_B_MASK_ID_B]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
