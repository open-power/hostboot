/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/mc/reg00010.H $           */
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

#ifndef __MC_REG00010_H_
#define __MC_REG00010_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_PERV_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT1_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT2_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT3_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT4_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT5_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT6_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT7_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT8_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT9_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT10_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT11_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT12_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT13_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CLOCK_STAT_SL_UNIT14_SL chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_0_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_1_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_2_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_3_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_4_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_5_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_6_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_7_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_8_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_9_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_10_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_11_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_12_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_13_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("0:scom_mc Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("1:scom_mc Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("2:scom_mc Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("3:scom_mc Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("4:scom_mc Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
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
    FAPI_ERR("5:scom_mc Invalid dial access CPLT_CTRL3_14_PSCOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL3_14_PSCOM_EN]

//>> PREP_[SCOMFIR_MCFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCFIR_RW]

//>> GET_[SCOMFIR_MCFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_RW;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RW]

//>> PUT_[SCOMFIR_MCFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFIR_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCFIR_RW]

//>> PREP_[SCOMFIR_MCFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCFIR_WO_AND]

//>> GET_[SCOMFIR_MCFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_WO_AND;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCFIR_WO_AND]

//>> PUT_[SCOMFIR_MCFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFIR_WO_AND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCFIR_WO_AND]

//>> PREP_[SCOMFIR_MCFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCFIR_WO_OR]

//>> GET_[SCOMFIR_MCFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIR_WO_OR;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCFIR_WO_OR]

//>> PUT_[SCOMFIR_MCFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFIR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCFIR_WO_OR]


//>> SET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]

//>> SET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]

//>> SET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]

//>> CLEAR_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]

//>> GET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]

//>> GET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]
static inline bool GET_SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MC_INTERNAL_RECOVERABLE_ERROR]

//>> SET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]

//>> SET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]

//>> SET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]

//>> CLEAR_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]

//>> GET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]

//>> GET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]
static inline bool GET_SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MC_INTERNAL_NONRECOVERABLE_ERROR]

//>> SET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]

//>> SET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]

//>> SET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]

//>> CLEAR_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]

//>> GET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]

//>> GET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]
static inline bool GET_SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_POWERBUS_PROTOCOL_ERROR]

//>> SET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]

//>> SET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]

//>> SET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]

//>> CLEAR_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]

//>> GET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]

//>> GET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]
static inline bool GET_SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_INBAND_BAR_HIT_WITH_INCORRECT_TTYPE]

//>> SET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]

//>> SET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]

//>> SET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]

//>> CLEAR_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]

//>> GET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]

//>> GET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]
static inline bool GET_SCOMFIR_MCFIR_MULTIPLE_BAR_HIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MULTIPLE_BAR_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_BAR_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MULTIPLE_BAR_HIT]

//>> SET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]

//>> SET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]

//>> SET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]

//>> CLEAR_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]

//>> GET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]

//>> GET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]
static inline bool GET_SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_PB_WRITE_ECC_SYNDROME_NE0]

//>> SET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]

//>> SET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]

//>> SET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]

//>> CLEAR_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]

//>> GET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]

//>> GET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]
static inline bool GET_P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCFIR_COMMAND_LIST_EARLY_HANG]

//>> SET_[SCOMFIR_MCFIR_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_6]

//>> SET_[SCOMFIR_MCFIR_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_6]

//>> SET_[SCOMFIR_MCFIR_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_6]

//>> CLEAR_[SCOMFIR_MCFIR_RESERVED_6]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_RESERVED_6]

//>> GET_[SCOMFIR_MCFIR_RESERVED_6]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_6]

//>> GET_[SCOMFIR_MCFIR_RESERVED_6]
static inline bool GET_SCOMFIR_MCFIR_RESERVED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_6]

//>> SET_[SCOMFIR_MCFIR_RESERVED_7]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_7]

//>> SET_[SCOMFIR_MCFIR_RESERVED_7]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_7]

//>> SET_[SCOMFIR_MCFIR_RESERVED_7]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_7]

//>> CLEAR_[SCOMFIR_MCFIR_RESERVED_7]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_RESERVED_7]

//>> GET_[SCOMFIR_MCFIR_RESERVED_7]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_7]

//>> GET_[SCOMFIR_MCFIR_RESERVED_7]
static inline bool GET_SCOMFIR_MCFIR_RESERVED_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_7]

//>> SET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]

//>> SET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]

//>> SET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]

//>> CLEAR_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]

//>> GET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]

//>> GET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]
static inline bool GET_SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_COMMAND_LIST_TIMEOUT]

//>> SET_[SCOMFIR_MCFIR_RESERVED_9]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_9]

//>> SET_[SCOMFIR_MCFIR_RESERVED_9]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_9]

//>> SET_[SCOMFIR_MCFIR_RESERVED_9]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_9]

//>> CLEAR_[SCOMFIR_MCFIR_RESERVED_9]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_RESERVED_9]

//>> GET_[SCOMFIR_MCFIR_RESERVED_9]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_9]

//>> GET_[SCOMFIR_MCFIR_RESERVED_9]
static inline bool GET_SCOMFIR_MCFIR_RESERVED_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_9]

//>> SET_[SCOMFIR_MCFIR_RESERVED_10]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_10]

//>> SET_[SCOMFIR_MCFIR_RESERVED_10]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_10]

//>> SET_[SCOMFIR_MCFIR_RESERVED_10]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_10]

//>> CLEAR_[SCOMFIR_MCFIR_RESERVED_10]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_RESERVED_10]

//>> GET_[SCOMFIR_MCFIR_RESERVED_10]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_10]

//>> GET_[SCOMFIR_MCFIR_RESERVED_10]
static inline bool GET_SCOMFIR_MCFIR_RESERVED_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_10]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT0]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT0]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT0]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT0]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT0]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MCS_WAT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT0]

//>> CLEAR_[SCOMFIR_MCFIR_MCS_WAT0]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MCS_WAT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_MCS_WAT0]

//>> GET_[SCOMFIR_MCFIR_MCS_WAT0]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MCS_WAT0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MCS_WAT0]

//>> GET_[SCOMFIR_MCFIR_MCS_WAT0]
static inline bool GET_SCOMFIR_MCFIR_MCS_WAT0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MCS_WAT0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MCS_WAT0]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT1]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT1]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT1]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT1]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT1]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MCS_WAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT1]

//>> CLEAR_[SCOMFIR_MCFIR_MCS_WAT1]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MCS_WAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_MCS_WAT1]

//>> GET_[SCOMFIR_MCFIR_MCS_WAT1]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MCS_WAT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MCS_WAT1]

//>> GET_[SCOMFIR_MCFIR_MCS_WAT1]
static inline bool GET_SCOMFIR_MCFIR_MCS_WAT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MCS_WAT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MCS_WAT1]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT2]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT2]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT2]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT2]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT2]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MCS_WAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT2]

//>> CLEAR_[SCOMFIR_MCFIR_MCS_WAT2]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MCS_WAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_MCS_WAT2]

//>> GET_[SCOMFIR_MCFIR_MCS_WAT2]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MCS_WAT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MCS_WAT2]

//>> GET_[SCOMFIR_MCFIR_MCS_WAT2]
static inline bool GET_SCOMFIR_MCFIR_MCS_WAT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MCS_WAT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MCS_WAT2]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT3]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT3]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT3]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MCS_WAT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT3]

//>> SET_[SCOMFIR_MCFIR_MCS_WAT3]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MCS_WAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MCS_WAT3]

//>> CLEAR_[SCOMFIR_MCFIR_MCS_WAT3]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MCS_WAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_MCS_WAT3]

//>> GET_[SCOMFIR_MCFIR_MCS_WAT3]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MCS_WAT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MCS_WAT3]

//>> GET_[SCOMFIR_MCFIR_MCS_WAT3]
static inline bool GET_SCOMFIR_MCFIR_MCS_WAT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MCS_WAT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_MCS_WAT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MCS_WAT3]

//>> SET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POP_RCMD_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]

//>> SET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POP_RCMD_NOHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]

//>> SET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]

//>> CLEAR_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]

//>> GET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_POP_RCMD_NOHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]

//>> GET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]
static inline bool GET_SCOMFIR_MCFIR_POP_RCMD_NOHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_POP_RCMD_NOHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_NOHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_POP_RCMD_NOHIT]

//>> SET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POP_RCMD_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]

//>> SET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_POP_RCMD_BADHIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]

//>> SET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]

//>> CLEAR_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]

//>> GET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_POP_RCMD_BADHIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]

//>> GET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]
static inline bool GET_SCOMFIR_MCFIR_POP_RCMD_BADHIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_POP_RCMD_BADHIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_POP_RCMD_BADHIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_POP_RCMD_BADHIT]

//>> SET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]

//>> SET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]

//>> SET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]

//>> CLEAR_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]

//>> GET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]

//>> GET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]
static inline bool GET_SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MS_WAT_DEBUG_CONFIG_REG_ERROR]

//>> SET_[SCOMFIR_MCFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_18]

//>> SET_[SCOMFIR_MCFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_18]

//>> SET_[SCOMFIR_MCFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_18]

//>> CLEAR_[SCOMFIR_MCFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_RESERVED_18]

//>> GET_[SCOMFIR_MCFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_18]

//>> GET_[SCOMFIR_MCFIR_RESERVED_18]
static inline bool GET_SCOMFIR_MCFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_18]

//>> SET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]

//>> SET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]

//>> SET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]

//>> CLEAR_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]

//>> GET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]

//>> GET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]
static inline bool GET_P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCFIR_READ0_OVERCOMMIT]

//>> SET_[SCOMFIR_MCFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_19]

//>> SET_[SCOMFIR_MCFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_19]

//>> SET_[SCOMFIR_MCFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_19]

//>> CLEAR_[SCOMFIR_MCFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_RESERVED_19]

//>> GET_[SCOMFIR_MCFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_19]

//>> GET_[SCOMFIR_MCFIR_RESERVED_19]
static inline bool GET_SCOMFIR_MCFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_19]

//>> SET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]

//>> SET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]

//>> SET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]

//>> CLEAR_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]

//>> GET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]

//>> GET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]
static inline bool GET_P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCFIR_READ1_OVERCOMMIT]

//>> SET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MULTIPLE_TID_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MULTIPLE_TID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_TID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]

//>> SET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MULTIPLE_TID_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_MULTIPLE_TID_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_TID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]

//>> SET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_MULTIPLE_TID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_MULTIPLE_TID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_TID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]

//>> CLEAR_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_MULTIPLE_TID_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_MULTIPLE_TID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_TID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]

//>> GET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_MULTIPLE_TID_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_MULTIPLE_TID_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_TID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]

//>> GET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]
static inline bool GET_SCOMFIR_MCFIR_MULTIPLE_TID_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_MULTIPLE_TID_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_MULTIPLE_TID_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_MULTIPLE_TID_ERROR]

//>> SET_[SCOMFIR_MCFIR_RESERVED_21]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_21]

//>> SET_[SCOMFIR_MCFIR_RESERVED_21]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_RESERVED_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_21]

//>> SET_[SCOMFIR_MCFIR_RESERVED_21]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_RESERVED_21]

//>> CLEAR_[SCOMFIR_MCFIR_RESERVED_21]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_RESERVED_21]

//>> GET_[SCOMFIR_MCFIR_RESERVED_21]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_RESERVED_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_21]

//>> GET_[SCOMFIR_MCFIR_RESERVED_21]
static inline bool GET_SCOMFIR_MCFIR_RESERVED_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_RESERVED_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_RESERVED_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_RESERVED_21]

//>> SET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_INVALID_SMF_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]

//>> SET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_INVALID_SMF_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]

//>> SET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_INVALID_SMF_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]

//>> CLEAR_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_INVALID_SMF_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]

//>> GET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_INVALID_SMF_ACCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]

//>> GET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]
static inline bool GET_SCOMFIR_MCFIR_INVALID_SMF_ACCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_INVALID_SMF_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_INVALID_SMF_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_INVALID_SMF_ACCESS]

//>> SET_[SCOMFIR_MCFIR_SYNC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_SYNC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_SYNC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIR_SYNC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_SYNC_ERROR]

//>> SET_[SCOMFIR_MCFIR_SYNC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_SYNC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIR_SYNC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIR_SYNC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_SYNC_ERROR]

//>> SET_[SCOMFIR_MCFIR_SYNC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIR_SYNC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.setBit<SCOMFIR_MCFIR_SYNC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCFIR_SYNC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIR_SYNC_ERROR]

//>> CLEAR_[SCOMFIR_MCFIR_SYNC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCFIR_SYNC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return o_data.clearBit<SCOMFIR_MCFIR_SYNC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCFIR_SYNC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCFIR_SYNC_ERROR]

//>> GET_[SCOMFIR_MCFIR_SYNC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIR_SYNC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIR_SYNC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIR_SYNC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_SYNC_ERROR]

//>> GET_[SCOMFIR_MCFIR_SYNC_ERROR]
static inline bool GET_SCOMFIR_MCFIR_SYNC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIR_RW, SCOMFIR_MCFIR_WO_AND, SCOMFIR_MCFIR_WO_OR));
#endif
    return i_data.getBit<SCOMFIR_MCFIR_SYNC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCFIR_SYNC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIR_SYNC_ERROR]

//>> PREP_[SCOMFIR_MCFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCFIRACT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIRACT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCFIRACT1]

//>> GET_[SCOMFIR_MCFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCFIRACT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCFIRACT1;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCFIRACT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCFIRACT1]

//>> PUT_[SCOMFIR_MCFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCFIRACT1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT1));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCFIRACT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCFIRACT1]


//>> SET_[SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1,
           SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1]

//>> SET_[SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1,
           SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1]

//>> GET_[SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCFIRACT1));
#endif
    return i_data.extractToRight<SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1,
           SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCFIRACT1_MCFIRACT1_ACTION_1]

//>> PREP_[SCOMFIR_MCMODE1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCOMFIR_MCMODE1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCMODE1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCOMFIR_MCMODE1]

//>> GET_[SCOMFIR_MCMODE1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCOMFIR_MCMODE1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCOMFIR_MCMODE1;
#endif
    return fapi2::getScom(i_target, SCOMFIR_MCMODE1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCOMFIR_MCMODE1]

//>> PUT_[SCOMFIR_MCMODE1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCOMFIR_MCMODE1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return fapi2::putScom(i_target, SCOMFIR_MCMODE1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCOMFIR_MCMODE1]


//>> SET_[SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY,
           SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY,
           SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY,
           SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_HIGH_PRIORITY]

//>> SET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]

//>> SET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]

//>> SET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]

//>> CLEAR_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]

//>> GET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]

//>> GET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]
static inline bool GET_SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_EN_BLOCK_PF_RD_IN_FLIGHT]

//>> SET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]

//>> SET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]

//>> SET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]

//>> CLEAR_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]

//>> GET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]

//>> GET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]
static inline bool GET_SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_EN_EPF_CL_LIMIT]

//>> SET_[SCOMFIR_MCMODE1_RESERVED_10]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_RESERVED_10]

//>> SET_[SCOMFIR_MCMODE1_RESERVED_10]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_RESERVED_10]

//>> SET_[SCOMFIR_MCMODE1_RESERVED_10]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_RESERVED_10]

//>> CLEAR_[SCOMFIR_MCMODE1_RESERVED_10]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_RESERVED_10]

//>> GET_[SCOMFIR_MCMODE1_RESERVED_10]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_RESERVED_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_RESERVED_10]

//>> GET_[SCOMFIR_MCMODE1_RESERVED_10]
static inline bool GET_SCOMFIR_MCMODE1_RESERVED_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_RESERVED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_RESERVED_10]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_CRC_ECC_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]

//>> CLEAR_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]
static inline bool GET_SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_FP_CRC_ECC_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]

//>> SET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]

//>> SET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]

//>> CLEAR_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]

//>> GET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]

//>> GET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]
static inline bool GET_SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_ENABLE_CRC_ECC_BYPASS_NODAL_ONLY]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE,
           SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE,
           SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE,
           SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_SPEC_SOURCE_SCOPE]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH,
           SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH,
           SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH,
           SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_CENTAUR_CMD_PREFETCH]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]

//>> CLEAR_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]
static inline bool GET_SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_ALL_SPEC_OPS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_SPEC_OP]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_SPEC_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_SPEC_OP,
           SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_SPEC_OP]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_SPEC_OP]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_SPEC_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_SPEC_OP,
           SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_SPEC_OP]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_SPEC_OP]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_SPEC_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_SPEC_OP,
           SCOMFIR_MCMODE1_DISABLE_SPEC_OP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_SPEC_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_SPEC_OP]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_CI]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CI,
           SCOMFIR_MCMODE1_DISABLE_CI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_CI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_CI]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_CI]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_CI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_CI,
           SCOMFIR_MCMODE1_DISABLE_CI_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_CI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_CI]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_CI]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_CI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_CI,
           SCOMFIR_MCMODE1_DISABLE_CI_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_CI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_CI]

//>> SET_[P10_20_SCOMFIR_MCMODE1_RESERVED_52_53]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCMODE1_RESERVED_52_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCMODE1_RESERVED_52_53,
           P10_20_SCOMFIR_MCMODE1_RESERVED_52_53_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE1_RESERVED_52_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCMODE1_RESERVED_52_53]

//>> SET_[P10_20_SCOMFIR_MCMODE1_RESERVED_52_53]
static inline fapi2::buffer<uint64_t>& SET_P10_20_SCOMFIR_MCMODE1_RESERVED_52_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<P10_20_SCOMFIR_MCMODE1_RESERVED_52_53,
           P10_20_SCOMFIR_MCMODE1_RESERVED_52_53_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE1_RESERVED_52_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_SCOMFIR_MCMODE1_RESERVED_52_53]

//>> GET_[P10_20_SCOMFIR_MCMODE1_RESERVED_52_53]
static inline fapi2::buffer<uint64_t>& GET_P10_20_SCOMFIR_MCMODE1_RESERVED_52_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<P10_20_SCOMFIR_MCMODE1_RESERVED_52_53,
           P10_20_SCOMFIR_MCMODE1_RESERVED_52_53_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access P10_20_SCOMFIR_MCMODE1_RESERVED_52_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_SCOMFIR_MCMODE1_RESERVED_52_53]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS,
           SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_COMMAND_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_RESERVED_60]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_RESERVED_60]

//>> SET_[SCOMFIR_MCMODE1_RESERVED_60]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_RESERVED_60]

//>> SET_[SCOMFIR_MCMODE1_RESERVED_60]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_RESERVED_60]

//>> CLEAR_[SCOMFIR_MCMODE1_RESERVED_60]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_RESERVED_60]

//>> GET_[SCOMFIR_MCMODE1_RESERVED_60]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_RESERVED_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_RESERVED_60]

//>> GET_[SCOMFIR_MCMODE1_RESERVED_60]
static inline bool GET_SCOMFIR_MCMODE1_RESERVED_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_RESERVED_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_RESERVED_60]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]

//>> CLEAR_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]
static inline bool GET_SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_FP_COMMAND_BYPASS]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]

//>> SET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]

//>> CLEAR_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]

//>> GET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]
static inline bool GET_SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_DISABLE_BYPASS_IN_READ_DATAFLOW]

//>> SET_[SCOMFIR_MCMODE1_RESERVED_63]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_RESERVED_63]

//>> SET_[SCOMFIR_MCMODE1_RESERVED_63]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.insertFromRight<SCOMFIR_MCMODE1_RESERVED_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_RESERVED_63]

//>> SET_[SCOMFIR_MCMODE1_RESERVED_63]
static inline fapi2::buffer<uint64_t>& SET_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.setBit<SCOMFIR_MCMODE1_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCOMFIR_MCMODE1_RESERVED_63]

//>> CLEAR_[SCOMFIR_MCMODE1_RESERVED_63]
static inline fapi2::buffer<uint64_t>& CLEAR_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return o_data.clearBit<SCOMFIR_MCMODE1_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCOMFIR_MCMODE1_RESERVED_63]

//>> GET_[SCOMFIR_MCMODE1_RESERVED_63]
static inline fapi2::buffer<uint64_t>& GET_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.extractToRight<SCOMFIR_MCMODE1_RESERVED_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_RESERVED_63]

//>> GET_[SCOMFIR_MCMODE1_RESERVED_63]
static inline bool GET_SCOMFIR_MCMODE1_RESERVED_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCOMFIR_MCMODE1));
#endif
    return i_data.getBit<SCOMFIR_MCMODE1_RESERVED_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_mc Invalid dial access SCOMFIR_MCMODE1_RESERVED_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCOMFIR_MCMODE1_RESERVED_63]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
